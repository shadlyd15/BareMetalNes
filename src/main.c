#include "util.h"
#include "screen.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "timer.h"
#include "system.h"
#include "keyboard.h"
#include "fpu.h"
#include "Adafruit_GFX.h"
#include "rom.c"

#define FPS 100

void _main(u32 magic) {

    idt_init();
    isr_init();
    fpu_init();
    irq_init();
    screen_init();
    timer_init();

    keyboard_init();
    Adafruit_GFX_Init(SCREEN_WIDTH, SCREEN_HEIGHT);

    u32 last_frame = 0;

    fce_load_rom((char*)rom);
    fce_init();
    print("Loading Emulator");
    while(true) {  
        int scanlines = 262;
        while (scanlines-- > 0){                   
            ppu_run(1);
            cpu_run(1364 / 12); // 1 scanline
        }
        const u32 now = (u32) timer_get();
        if ((now - last_frame) > (TIMER_TPS / FPS)) {
            last_frame = now;
            screen_swap();
        }
    }
}
