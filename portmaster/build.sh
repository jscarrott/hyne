#!/bin/bash
# Builds the PortMaster package for Knulli (and any other aarch64 CFW).
#
# Run it inside the container built from portmaster/Dockerfile, or on any
# aarch64 Debian bookworm machine with the same packages installed. Building
# on a newer distribution links against a newer glibc than the handhelds ship.
#
#   portmaster/build-in-docker.sh          # from an x86_64 or aarch64 host
#   portmaster/build.sh                    # inside the container
#
# Output: dist/hyne.zip

set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="${BUILD_DIR:-$ROOT/.build-portmaster}"
INSTALL_DIR="$BUILD_DIR/install"
STAGE_DIR="$BUILD_DIR/stage"
DIST_DIR="${DIST_DIR:-$ROOT/dist}"
PORT_DIR="$STAGE_DIR/hyne"

# Libraries that must come from the device, see device-libs.txt
SYSTEM_LIBS="$(grep -v '^\s*\(#\|$\)' "$ROOT/portmaster/device-libs.txt")"

is_system_lib() {
	local name
	name="$(basename "$1")"
	for pattern in $SYSTEM_LIBS; do
		case "$name" in
			"$pattern"*) return 0 ;;
		esac
	done
	return 1
}

echo "==> Building Hyne"
cmake -S "$ROOT" -B "$BUILD_DIR" -G Ninja \
	-DCMAKE_BUILD_TYPE=Release \
	-DENABLE_JP_ENCODING=ON \
	-DCMAKE_INSTALL_PREFIX="$INSTALL_DIR"
cmake --build "$BUILD_DIR" -j"$(nproc)"
cmake --install "$BUILD_DIR" > /dev/null

echo "==> Staging the port"
rm -rf "$STAGE_DIR"
mkdir -p "$PORT_DIR"/{libs,plugins,translations,fonts,licenses,conf}

cp "$INSTALL_DIR/bin/Hyne" "$PORT_DIR/hyne"
cp "$INSTALL_DIR"/share/hyne/translations/*.qm "$PORT_DIR/translations/"

QT_PLUGINS="$(qmake6 -query QT_INSTALL_PLUGINS)"
# linuxfb and eglfs are the two ways to reach the screen without X11,
# offscreen keeps the package testable under qemu
for plugin in \
	platforms/libqlinuxfb.so \
	platforms/libqeglfs.so \
	platforms/libqoffscreen.so \
	platforms/libqminimal.so \
	generic/libqevdevmouseplugin.so \
	generic/libqevdevkeyboardplugin.so \
	generic/libqevdevtouchplugin.so
do
	if [ -f "$QT_PLUGINS/$plugin" ]; then
		mkdir -p "$PORT_DIR/plugins/$(dirname "$plugin")"
		cp "$QT_PLUGINS/$plugin" "$PORT_DIR/plugins/$plugin"
	else
		echo "    missing plugin: $plugin"
	fi
done
for dir in imageformats egldeviceintegrations; do
	if [ -d "$QT_PLUGINS/$dir" ]; then
		mkdir -p "$PORT_DIR/plugins/$dir"
		cp "$QT_PLUGINS/$dir"/*.so "$PORT_DIR/plugins/$dir/"
	fi
done

echo "==> Collecting libraries"
# Walk the dependency closure of the binary and of every plugin
while :; do
	added=0
	while read -r target; do
		while read -r _name _arrow path _address; do
			[ -f "${path:-}" ] || continue
			is_system_lib "$path" && continue
			dest="$PORT_DIR/libs/$(basename "$path")"
			if [ ! -f "$dest" ]; then
				cp -L "$path" "$dest"
				added=$((added + 1))
			fi
		done < <(ldd "$target" 2>/dev/null | grep '=>')
	done < <(find "$PORT_DIR" -name '*.so*' -o -name hyne | sort)

	[ "$added" -eq 0 ] && break
done
echo "    $(find "$PORT_DIR/libs" -name '*.so*' | wc -l) libraries bundled"

# libudev belongs to the device, but not every firmware has one, and both the
# framebuffer plugin and the KMS integration need it. It travels in its own
# directory, which the launcher only uses when the device has none.
echo "==> Fallback libraries"
mkdir -p "$PORT_DIR/libs.fallback"
for lib in $(ldconfig -p | sed -n 's/.*libudev\.so\.1 (libc6[^)]*) => \(.*\)/\1/p' | head -1); do
	cp -L "$lib" "$PORT_DIR/libs.fallback/"
done
if [ ! -f "$PORT_DIR/libs.fallback/libudev.so.1" ]; then
	echo "    warning: no libudev.so.1 found to use as a fallback"
fi

echo "==> Fonts"
for font in DejaVuSans.ttf DejaVuSans-Bold.ttf; do
	find /usr/share/fonts -name "$font" -exec cp {} "$PORT_DIR/fonts/" \; -quit
done
cat > "$PORT_DIR/fonts/fonts.conf" <<'EOF'
<?xml version="1.0"?>
<!DOCTYPE fontconfig SYSTEM "fonts.dtd">
<fontconfig>
	<!-- Hyne.sh runs the binary from the port directory -->
	<dir prefix="cwd">fonts</dir>
	<cachedir prefix="cwd">conf/fontconfig</cachedir>
	<match target="pattern">
		<edit name="family" mode="prepend"><string>DejaVu Sans</string></edit>
	</match>
</fontconfig>
EOF

cat > "$PORT_DIR/qt.conf" <<'EOF'
[Paths]
Prefix = .
Plugins = plugins
Translations = translations
Libraries = libs
EOF

echo "==> Port files"
cp "$ROOT/portmaster/hyne/hyne.gptk."* "$PORT_DIR/"
cp "$ROOT/portmaster/hyne/hyne.cfg" "$PORT_DIR/"
cp "$ROOT/COPYING.txt" "$PORT_DIR/licenses/LICENSE"
cp "$ROOT/portmaster/Hyne.sh" "$STAGE_DIR/"
cp "$ROOT/portmaster/port.json" "$STAGE_DIR/"
cp "$ROOT/portmaster/README.md" "$STAGE_DIR/"
cp "$ROOT/portmaster/gameinfo.xml" "$STAGE_DIR/"
cp "$ROOT/portmaster/screenshot.jpg" "$STAGE_DIR/"
chmod +x "$STAGE_DIR/Hyne.sh" "$PORT_DIR/hyne"

strip --strip-unneeded "$PORT_DIR/hyne" "$PORT_DIR"/libs/*.so* "$PORT_DIR"/plugins/*/*.so 2>/dev/null || true

echo "==> Packaging"
mkdir -p "$DIST_DIR"
rm -f "$DIST_DIR/hyne.zip"
(cd "$STAGE_DIR" && zip -qr "$DIST_DIR/hyne.zip" .)

echo "==> $DIST_DIR/hyne.zip ($(du -h "$DIST_DIR/hyne.zip" | cut -f1))"
