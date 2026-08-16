#!/bin/bash
# Renders Hyne at a handheld resolution and captures every editor page, so the
# compact layout can be checked without a device.
#
# Usage: portmaster/tools/screenshot-pages.sh [binary] [save file] [output dir]
#
# Requires: Xvfb, xdotool, imagemagick

set -euo pipefail

BINARY="${1:-$(dirname "$0")/../../.build-local/Hyne}"
SAVE="${2:-}"
OUTDIR="${3:-/tmp/hyne-shots}"
RESOLUTION="${RESOLUTION:-640x480}"
DISPLAY_NUM="${DISPLAY_NUM:-:99}"

mkdir -p "$OUTDIR"

if [ -z "$SAVE" ]; then
    # A new game save, extracted from the one embedded in Hyne itself
    SAVE="$OUTDIR/init.out"
    dd if="$(dirname "$0")/../../src/qt/data/newGame" of="$SAVE" \
       bs=1 skip=464 count=2812 status=none
fi

Xvfb "$DISPLAY_NUM" -screen 0 "${RESOLUTION}x24" &
XVFB_PID=$!
trap 'kill $XVFB_PID 2>/dev/null || true' EXIT
sleep 2

export DISPLAY="$DISPLAY_NUM"
export HYNE_COMPACT=1
export XDG_CONFIG_HOME="$OUTDIR/config"
mkdir -p "$XDG_CONFIG_HOME"
# Skip the language chooser shown when the system locale is unknown
printf '[General]\nlang=en\n' > "$XDG_CONFIG_HOME/Hyne.conf"

"$BINARY" "$SAVE" &
HYNE_PID=$!
trap 'kill $HYNE_PID 2>/dev/null || true; kill $XVFB_PID 2>/dev/null || true' EXIT
sleep 3

# Dismiss the format notice shown for some save types
xdotool key Return
sleep 1

shot() {
    import -window root "$OUTDIR/$1.png"
    echo "$OUTDIR/$1.png"
}

# Memory card view
shot "00-savecard"

# Open the first save in the editor
xdotool mousemove 320 50 click 1
sleep 2
shot "01-editor-page01"

# Walk every page with the shoulder button shortcut
for i in $(seq 2 15); do
    xdotool key ctrl+Next
    sleep 1
    shot "$(printf '%02d-editor-page%02d' "$i" "$i")"
done

kill $HYNE_PID 2>/dev/null || true
wait $HYNE_PID 2>/dev/null || true
echo "Screenshots written to $OUTDIR"
