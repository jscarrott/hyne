# Build environment for the PortMaster package.
#
# Debian bookworm ships glibc 2.36 and Qt 6.4, both older than what Knulli and
# the other aarch64 CFWs run, so the resulting binary and the bundled Qt work
# there. Building on a newer distribution produces a package that fails to
# start with "GLIBC_2.3x not found".
FROM arm64v8/debian:bookworm

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        ninja-build \
        pkg-config \
        zip \
        zlib1g-dev \
        qt6-base-dev \
        qt6-base-dev-tools \
        qt6-tools-dev \
        qt6-tools-dev-tools \
        qt6-l10n-tools \
        qt6-5compat-dev \
        libqt6opengl6-dev \
        fonts-dejavu-core \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
ENTRYPOINT ["/src/portmaster/build.sh"]
