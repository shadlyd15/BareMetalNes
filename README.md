
# BareMetalNes
A NES Emulator running on x86 CPU without an OS. The emulator part is a port of [LiteNES](https://github.com/NJU-ProjectN/LiteNES) and the low level drivers are taken from amazing [Tetris OS](https://www.youtube.com/watch?v=FaILnmUYS_U) by [jdh](https://github.com/jdah). 

## Compile BareMetalNes

    make

## Make Image

    make img

## Run in QEMU

    make run

## Issues
- No file system is implemented yet. So rom is statically added in the code. Use **rom_helper.c** to convert rom.
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