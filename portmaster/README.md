# Hyne

A complete savegame editor for Final Fantasy VIII, running on the handheld
itself. It opens PlayStation memory cards (`.mcr`, `.mcd`, `.srm`, `.gme`,
`.vgs`, `.vmp`, `.psv`, ePSXe save states) as well as PC, PS4 Remaster and
Switch saves.

Hyne is written by myst6re and released under the GPLv3. Source:
<https://github.com/myst6re/hyne>.

## Where to put your saves

Open the memory card your emulator writes:

| Emulator | Path |
| --- | --- |
| PCSX-ReARMed, SwanStation, Beetle PSX | `/userdata/saves/psx` |
| DuckStation standalone | `/userdata/saves/duckstation/memcards` |
| Anything else | wherever your rom lives, `/roms/psx` |

The Open dialog starts in the first of those directories that exists. Set
`HYNE_SAVEDIR` in `hyne/hyne.cfg` to change it.

**Back up the file before editing it.** Hyne writes the memory card in place.

## Controls

| Button | Action |
| --- | --- |
| Left stick | Move the pointer (d-pad on devices without a stick) |
| D-pad | Move between controls |
| A | Click |
| B | Escape / close a dialog |
| X | Enter / validate |
| Y | Tab to the next control |
| L1 / R1 | Previous / next editor page |
| L2 / R2 | Scroll the page |
| L3 | Slow the pointer down |
| Start | Open the menu bar |
| Select + Start | Quit |

Renaming characters, GFs or Griever needs a USB or Bluetooth keyboard: this
port ships no on screen keyboard. Everything else — stats, magic, items,
abilities, shops, Triple Triad, gil, the save header — is editable with the
gamepad alone.

## If the screen stays black

The port picks a Qt display backend automatically: the framebuffer when
`/dev/fb0` exists, KMS/DRM otherwise. The choice is printed on the first line
of `hyne/log.txt`. To force the other one, edit `hyne/hyne.cfg`:

```sh
HYNE_PLATFORM=eglfs     # or linuxfb
```

`hyne/log.txt` is rewritten on every launch and is the first thing to look at
when something goes wrong.

## Small screens

The interface is laid out for 640x480 and most pages fit without scrolling.
Worldmap and Miscellaneous are wider and scroll sideways. To see them whole,
shrink the whole interface in `hyne/hyne.cfg`:

```sh
HYNE_SCALE=0.85
```

## Building the package

From a checkout of this repository:

```sh
portmaster/build-in-docker.sh     # produces dist/hyne.zip
```

The build runs in Debian bookworm on aarch64 (glibc 2.36, Qt 6.4) so the
binary and the bundled Qt libraries are older than what the firmware ships.
`portmaster/build.sh` does the same thing when run directly on an aarch64
Debian machine.
