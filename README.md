# DeeS
Experimental Nintendo DS emulator written in C++ and Kotlin.

<span>
  <img src="https://img.shields.io/static/v1?label=Built%20with&message=C%2B%2B&color=blue"/>
  <img src="https://img.shields.io/static/v1?label=Built%20with&message=Kotlin&color=blueviolet"/>
  <img src="https://img.shields.io/static/v1?label=License&message=GPLv3&color=blue"/>
  <img src="https://img.shields.io/static/v1?label=Supports&message=Android 12%2B&color=green"/>
</span>
<br/>
<span>
  <a href="https://buymeacoffee.com/antiquecodes">
    <img src="https://img.shields.io/static/v1?label=Support&message=Buy%20Me%20A%20Coffee&color=yellow"/>
  </a>
  <a href="https://paypal.com/paypalme/officialantique">
    <img src="https://img.shields.io/static/v1?label=Support&message=PayPal&color=009cde"/>
  </a>
</span>

# Core
> **Note**: DeeS currently uses NooDS as its emulation core. DeeS will receive a complete emulation core rewrite in the future.

## Requirements
### Filesystem Example
- `.../Android/media/com.antique.dees`
  - `/core`
    - `bios7.bin` (required by user, may be named .rom) - [LMGT](https://letmegooglethat.com/?q=nintendo+ds+bios)
    - `bios9.bin` (required by user, may be named .rom) - [LMGT](https://letmegooglethat.com/?q=nintendo+ds+bios)
    - `firmware.bin` (required by user, may be named .rom) - [LMGT](https://letmegooglethat.com/?q=nintendo+ds+bios)
    - `gba_bios.bin` (required by user, may be named .rom) - [LMGT](https://letmegooglethat.com/?q=nintendo+ds+bios)
    - `sd.img` (optional, may be named .raw, 64 MB recommended) - [Virtual SD Card Maker](https://www.mediafire.com/file/cfr9q8542e9lsos/Virtual_SD_Card_Maker.zip/file)
  - `/roms`
    - Place .gb, .gba or .nds roms here.
  - `dees.ini`

## Latest Changes
> 2nd December 2022

- Added native controller support.
- Added multi-threading option in settings (off = 2, on = 4).
- Removed 3 thread limit on 3D emulation.

## Previous Changes
> 1st December 2022

- Fixed an issue where games would not save upon exiting the game.
- Removed root requirement by transitioning to Scoped Storage.

## Social Media
<span>
  <img src="https://img.shields.io/static/v1?label=Discord&message=Antique%239837&color=blueviolet"/>
  <a href="https://reddit.com/u/antique_codes">
    <img src="https://img.shields.io/static/v1?label=Reddit&message=%40antique_codes&color=red"/>
  </a>
  <a href="https://twitch.tv/official_antique">
    <img src="https://img.shields.io/static/v1?label=Twitch&message=official_antique&color=blueviolet"/>
  </a>
  <a href="https://twitter.com/antique_codes">
    <img src="https://img.shields.io/static/v1?label=Twitter&message=%40antique_codes&color=blue"/>
  </a>
</span>
