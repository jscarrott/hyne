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

The interface is driven with the d-pad: it walks through the controls and
changes their values, so nothing needs the pointer.

| Button | Action |
| --- | --- |
| D-pad up / down | Move to the previous / next control |
| D-pad left / right | Change the focused value, move inside a list |
| A | Activate: press a button, tick a box, open a save |
| B | Escape, close a dialog |
| X | Confirm a dialog, commit a field |
| Y | Jump to the next control (out of a list) |
| L1 / R1 | Previous / next editor page |
| L2 / R2 | Scroll a page, jump through the memory card |
| Start | Open the menu bar |
| Select + Start | Quit |
| Left stick | Move the pointer, L3 clicks (devices with a stick) |
| Right stick | Scroll (devices with two sticks) |

The focused control is outlined, that outline is where the d-pad acts.

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
Worldmap and Miscellaneous are wider and scroll sideways.

On a 3.5 inch panel — RG35XX Pro, Plus, H and SP all pack 640x480 into
3.5 inches — the default 8 point font is small. Turn it up in
`hyne/hyne.cfg`:

```sh
HYNE_FONT_SIZE=10
```

10 still fits every page that fitted before; above that the wider pages
start scrolling sideways. The page list grows with the font so the page
names stay readable.

`HYNE_SCALE` is the opposite trade, shrinking everything to get more of the
widest pages on screen at once.

## Building the package

From a checkout of this repository:

```sh
portmaster/build-in-docker.sh     # produces dist/hyne.zip
```

The build runs in Debian bookworm on aarch64 (glibc 2.36, Qt 6.4) so the
binary and the bundled Qt libraries are older than what the firmware ships.
`portmaster/build.sh` does the same thing when run directly on an aarch64
Debian machine.
