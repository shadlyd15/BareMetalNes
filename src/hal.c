/*
This file presents all abstractions needed to port LiteNES.
  (The current working implementation uses allegro library.)

To port this project, replace the following functions by your own:
1) nes_hal_init()
    Do essential initialization work, including starting a FPS HZ timer.

2) nes_set_bg_color(c)
    Set the back ground color to be the NES internal color code c.

3) nes_flush_buf(*buf)
    Flush the entire pixel buf's data to frame buffer.

4) nes_flip_display()
    Fill the screen with previously set background color, and
    display all contents in the frame buffer.

5) wait_for_frame()
    Implement it to make the following code is executed FPS times a second:
        while (1) {
            wait_for_frame();
            do_something();
        }

6) int nes_key_state(int b) 
    Query button b's state (1 to be pressed, otherwise 0).
    The correspondence of b and the buttons:
      0 - Power
      1 - A
      2 - B
      3 - SELECT
      4 - START
      5 - UP
      6 - DOWN
      7 - LEFT
      8 - RIGHT
*/
#include "hal.h"
#include "fce.h"
#include "common.h"
#include "screen.h"
#include "Adafruit_GFX.h"
#include "nes_key.h"

  

int nes_paletto(int i){
    pal color = palette[i];
    u8 red = color.r * (7.0 / 0xFF);
    u8 green = color.g * (7.0 / 0xFF);
    u8 blue = color.b * (3.0 / 0xFF);

    return COLOR(red, green, blue);
}


static volatile int timers = 0, live = 0;
/* Wait until next allegro timer event is fired. */
void wait_for_frame()
{
    // u64 te = ;
    // while(!(timer_get()%10000));
}

/* Set background color. RGB value of c is defined in fce.h */
void nes_set_bg_color(int c)
{
    // pal mai = palette[c];
    fillScreen(nes_palette(c));
}

/* Flush the pixel buffer */
void nes_flush_buf(PixelBuf *buf) {

}

/* Initialization: 
   (1) start a 1/FPS Hz timer. 
   (2) register fce_timer handle on each timer event */
void nes_hal_init()
{

}


void nes_draw_pixel(Pixel *p)
{ 
    u8 color = p->c;
    // int idx = ppu_ram_read(0x3F00);
    // // // pal mai = palette[color];
    // nes_set_bg_color(nes_paletto(color));
    if(p->x > -1){
        drawPixel(p->x * 5/4, p->y * 5/6, nes_paletto(color));
        if(!(p->x & 0x3))
        drawPixel(p->x * 5/4 -1, p->y * 5/6, nes_paletto(color));
    }
}

/* Update screen at FPS rate by allegro's drawing function. 
   Timer ensures this function is called FPS times a second. */
void nes_flip_display()
{

}

/* Query a button's state.
   Returns 1 if button #b is pressed. */
int nes_key_state(int b)
{
    return GetKey(b);
}

