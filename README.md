# BareMetalNes
A bootable NES Emulator running on x86 CPU without an OS. The emulator part is a port of [LiteNES](https://github.com/NJU-ProjectN/LiteNES) and the low level drivers are taken from amazing [Tetris OS](https://www.youtube.com/watch?v=FaILnmUYS_U) by [jdh](https://github.com/jdah). 

## Compile 
    make

## Make Image
    make img

## Run in QEMU
    make run

## Make Clean
    make clean

# Demo Video on QEMU
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/Wji7yl82ixY/0.jpg)](https://www.youtube.com/watch?v=Wji7yl82ixY)


Watch on Youtube :  [https://www.youtube.com/watch?v=Wji7yl82ixY](https://www.youtube.com/watch?v=Wji7yl82ixY)

## Known Issues
-   No file system is implemented yet. So rom is statically added in the code. Use **rom_helper.c** to convert rom.
-   Mappers are not implemented yet.
-   It does not support Audio emulation yet.
-   Only single player is supported.
-   NesUEFI only supports PS/2 keyboard. Most of the laptop keyboards should support it.

## Controls 
| NesUEFI Key | Keyboard Key |  
| ----------- | ----------- |  
| Up | W |
| Down | S |
| Left | A |
| Right | D |
| Select | U |
| Start | I |
| A | K |
| B | J |
| Reload | R |