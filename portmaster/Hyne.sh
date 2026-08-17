#!/bin/bash

XDG_DATA_HOME=${XDG_DATA_HOME:-$HOME/.local/share}

if [ -d "/opt/system/Tools/PortMaster/" ]; then
  controlfolder="/opt/system/Tools/PortMaster"
elif [ -d "/opt/tools/PortMaster/" ]; then
  controlfolder="/opt/tools/PortMaster"
elif [ -d "$XDG_DATA_HOME/PortMaster/" ]; then
  controlfolder="$XDG_DATA_HOME/PortMaster"
else
  controlfolder="/roms/ports/PortMaster"
fi

source $controlfolder/control.txt

[ -f "${controlfolder}/mod_${CFW_NAME}.txt" ] && source "${controlfolder}/mod_${CFW_NAME}.txt"

get_controls

GAMEDIR=/$directory/ports/hyne
CONFDIR="$GAMEDIR/conf"

mkdir -p "$CONFDIR"
# Qt complains about a world writable XDG_RUNTIME_DIR
chmod 700 "$CONFDIR" 2>/dev/null
cd "$GAMEDIR"

> "$GAMEDIR/log.txt" && exec > >(tee "$GAMEDIR/log.txt") 2>&1

# Optional user overrides, see hyne.cfg
[ -f "$GAMEDIR/hyne.cfg" ] && source "$GAMEDIR/hyne.cfg"

export LD_LIBRARY_PATH="$GAMEDIR/libs:$LD_LIBRARY_PATH"

# The display plugins need libudev. It normally belongs to the device, but
# not every firmware ships one, and without it they fail to load with no
# explanation at all.
if [ -e /usr/lib/libudev.so.1 ] || [ -e /lib/libudev.so.1 ] \
   || ldconfig -p 2>/dev/null | grep -q "libudev.so.1"; then
  echo "libudev: using the one on the device"
else
  echo "libudev: none on the device, using the bundled one"
  export LD_LIBRARY_PATH="$GAMEDIR/libs.fallback:$LD_LIBRARY_PATH"
fi
export QT_PLUGIN_PATH="$GAMEDIR/plugins"
export FONTCONFIG_FILE="$GAMEDIR/fonts/fonts.conf"
export QT_QPA_FONTDIR="$GAMEDIR/fonts"

# Keep everything Hyne writes inside the port directory
export HOME="$CONFDIR"
export XDG_CONFIG_HOME="$CONFDIR"
export XDG_DATA_HOME="$CONFDIR"
export XDG_CACHE_HOME="$CONFDIR"
export XDG_RUNTIME_DIR="$CONFDIR"

# Hyne's handheld layout
export HYNE_COMPACT=1
[ -n "$HYNE_SCALE" ] && export QT_SCALE_FACTOR="$HYNE_SCALE"
[ -n "$HYNE_FONT_SIZE" ] && export HYNE_FONT_SIZE

# There is no X server here. Which of the two ways to reach the screen works
# depends on the device, and a backend can be present and still refuse to
# start, so the ones that could work are tried in turn rather than picked.
if [ -n "$HYNE_PLATFORM" ]; then
  PLATFORMS="$HYNE_PLATFORM"
else
  PLATFORMS=""
  [ -e /dev/fb0 ] && PLATFORMS="linuxfb"
  [ -e /dev/dri/card0 ] && PLATFORMS="$PLATFORMS eglfs"
  [ -n "$PLATFORMS" ] || PLATFORMS="linuxfb eglfs"
fi
echo "Qt platforms to try: $PLATFORMS"

# Only eglfs can turn the picture, the framebuffer one shows it as the
# panel is wired
[ -n "$HYNE_ROTATION" ] && export QT_QPA_EGLFS_ROTATION="$HYNE_ROTATION"

# Read the keyboard and the mouse gptokeyb emulates straight from evdev,
# instead of depending on the libinput of the device
export QT_QPA_FB_DISABLE_INPUT=1
export QT_QPA_EGLFS_DISABLE_INPUT=1
export QT_QPA_GENERIC_PLUGINS=evdevmouse,evdevkeyboard
export QT_QPA_FB_HIDECURSOR=0
export QT_QPA_EGLFS_HIDECURSOR=0

# First run: open the file dialog where the emulators keep their memory cards
if [ ! -f "$CONFDIR/Hyne.conf" ]; then
  SAVEDIR="$HYNE_SAVEDIR"
  if [ -z "$SAVEDIR" ]; then
    for candidate in /userdata/saves/psx /userdata/saves/psx/pcsx_rearmed "/$directory/psx"; do
      if [ -d "$candidate" ]; then
        SAVEDIR="$candidate"
        break
      fi
    done
  fi
  {
    echo "[General]"
    echo "lang=en"
    [ -n "$SAVEDIR" ] && echo "loadPath=$SAVEDIR"
  } > "$CONFDIR/Hyne.conf"
fi

chmod +x "$GAMEDIR/hyne"

# gptokeyb reports one gptk per stick count, fall back to the one stick map
GPTK="$GAMEDIR/hyne.gptk.${ANALOGSTICKS:-1}"
[ -f "$GPTK" ] || GPTK="$GAMEDIR/hyne.gptk.1"

$GPTOKEYB "hyne" -c "$GPTK" &
pm_platform_helper "$GAMEDIR/hyne"

# Qt lists the input devices once at startup, give gptokeyb the time to
# create the virtual keyboard and mouse it feeds them from
sleep 1

for platform in $PLATFORMS; do
  echo "Starting with Qt platform: $platform"
  QT_QPA_PLATFORM="$platform" ./hyne
  status=$?
  # 0 is a normal quit, 143 is the SIGTERM of Select+Start
  if [ $status -eq 0 ] || [ $status -eq 143 ]; then
    break
  fi
  echo "Qt platform $platform failed with status $status"
  LAST_STATUS=$status
done

if [ -n "$LAST_STATUS" ] && [ "$LAST_STATUS" != "0" ]; then
  echo
  echo "=== No Qt platform worked, here is why ==="
  echo "--- libraries the plugins cannot find:"
  ldd plugins/platforms/libqlinuxfb.so \
      plugins/egldeviceintegrations/libqeglfs-kms-integration.so 2>/dev/null \
    | grep "not found" | sort -u
  echo "--- what the device provides:"
  ls -l /usr/lib/libudev.so.1 /lib/libudev.so.1 /usr/lib/libgbm.so.1 \
        /usr/lib/libdrm.so.2 /dev/fb0 /dev/dri/card0 2>&1 | sed 's/^/    /'
  echo "--- Qt plugin loader:"
  QT_DEBUG_PLUGINS=1 QT_QPA_PLATFORM="${PLATFORMS%% *}" ./hyne 2>&1 \
    | grep -iE "cannot load|not found|failed|no such" | head -20
  echo "=== end ==="
fi

pm_finish
