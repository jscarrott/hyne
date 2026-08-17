#!/bin/bash
# Checks that a built port bundle carries every library it needs, apart from
# the ones that deliberately come from the device (portmaster/device-libs.txt).
#
# Usage: portmaster/tools/check-package.sh [dist/hyne.zip | port directory]
#
# Reads the DT_NEEDED entries of the binary and of every bundled library and
# plugin, rather than asking the dynamic loader: ldd resolves against the
# libraries of the machine running it, which both hides libraries missing from
# the bundle and reports the device ones as broken. Reading the ELF headers
# gives the same answer on any host, for a package built for any architecture.

set -euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
TARGET="${1:-$ROOT/dist/hyne.zip}"
DEVICE_LIBS="$ROOT/portmaster/device-libs.txt"

if [ -d "$TARGET" ]; then
	PORT_DIR="$TARGET"
else
	TMP_DIR="$(mktemp -d)"
	trap 'rm -rf "$TMP_DIR"' EXIT
	unzip -q "$TARGET" -d "$TMP_DIR"
	PORT_DIR="$TMP_DIR/hyne"
fi

[ -f "$PORT_DIR/hyne" ] || { echo "no hyne binary in $PORT_DIR"; exit 1; }

device_pattern="$(grep -v '^\s*\(#\|$\)' "$DEVICE_LIBS" | paste -sd '|')"

missing=""
checked=0

while read -r file; do
	checked=$((checked + 1))
	while read -r needed; do
		[ -n "$needed" ] || continue
		[ -f "$PORT_DIR/libs/$needed" ] && continue
		[ -f "$PORT_DIR/libs.fallback/$needed" ] && continue
		# Provided by the device
		printf '%s' "$needed" | grep -qE "^($device_pattern)" && continue
		missing="$missing$needed (needed by ${file#"$PORT_DIR/"})"$'\n'
	done < <(readelf -d "$file" 2>/dev/null | sed -n 's/.*(NEEDED).*\[\(.*\)\]/\1/p')
done < <(find "$PORT_DIR" -type f \( -name '*.so*' -o -name hyne \) | sort)

if [ -n "$missing" ]; then
	echo "Libraries neither bundled nor provided by the device:"
	printf '%s' "$missing" | sort -u
	exit 1
fi

echo "OK: $checked files checked, $(find "$PORT_DIR/libs" -name '*.so*' | wc -l) libraries bundled, nothing unresolved"
