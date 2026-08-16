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
cd "$GAMEDIR"

> "$GAMEDIR/log.txt" && exec > >(tee "$GAMEDIR/log.txt") 2>&1

# Optional user overrides, see hyne.cfg
[ -f "$GAMEDIR/hyne.cfg" ] && source "$GAMEDIR/hyne.cfg"

export LD_LIBRARY_PATH="$GAMEDIR/libs:$LD_LIBRARY_PATH"
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

# There is no X server here: paint on the framebuffer when there is one,
# through KMS/DRM otherwise
if [ -z "$HYNE_PLATFORM" ]; then
  if [ -e /dev/fb0 ]; then
    HYNE_PLATFORM="linuxfb"
  elif [ -e /dev/dri/card0 ]; then
    HYNE_PLATFORM="eglfs"
  else
    HYNE_PLATFORM="linuxfb"
  fi
fi
export QT_QPA_PLATFORM="$HYNE_PLATFORM"
# Only eglfs can turn the picture, the framebuffer one shows it as the
# panel is wired
[ -n "$HYNE_ROTATION" ] && export QT_QPA_EGLFS_ROTATION="$HYNE_ROTATION"
echo "Using Qt platform: $QT_QPA_PLATFORM"

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

./hyne

pm_finish
