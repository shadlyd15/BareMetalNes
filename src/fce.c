#include "fce.h"
#include "cpu.h"
#include "memory.h"
#include "ppu.h"
#include "hal.h"
#include "nes.h"
#include "util.h"

#include "screen.h"

PixelBuf bg, bbg, fg;

typedef struct {
    char signature[4];
    byte prg_block_count;
    byte chr_block_count;
    word rom_type;
    byte reserved[8];
} ines_header;

static ines_header fce_rom_header;

// FCE Lifecycle

void
romread(char *rom, void *buf, int size)
{
    static int off = 0;
    memcpy(buf, rom + off, size);
    off += size;
}

int fce_load_rom(char *rom)
{
    romread(rom, &fce_rom_header, sizeof(fce_rom_header));

    if (memcmp(fce_rom_header.signature, "NES\x1A", 4)) {
        return -1;
    }
    // return 1;
    mmc_id = ((fce_rom_header.rom_type & 0xF0) >> 4);

    int prg_size = fce_rom_header.prg_block_count * 0x4000;
    static byte buf[1048576];
    romread(rom, buf, prg_size);

    if (mmc_id == 0 || mmc_id == 3) {
        // if there is only one PRG block, we must repeat it twice
        if (fce_rom_header.prg_block_count == 1) {
            mmc_copy(0x8000, buf, 0x4000);
            mmc_copy(0xC000, buf, 0x4000);
        }
        else {
            mmc_copy(0x8000, buf, 0x8000);
        }
    }
    else {
        return -1;
    }

    // Copying CHR pages into MMC and PPU
    int i;
    for (i = 0; i < fce_rom_header.chr_block_count; i++) {
        romread(rom, buf, 0x2000);
        mmc_append_chr_rom_page(buf);

        if (i == 0) {
            ppu_copy(0x0000, buf, 0x2000);
        }
    }

    return 0;
}



void fce_init()
{
    nes_hal_init();
    cpu_init();
    ppu_init();
    ppu_set_mirroring(fce_rom_header.rom_type & 1);
    cpu_reset();
}

void wait_for_frame();

void fce_run()
{
    while(1)
    {
        wait_for_frame();
        int scanlines = 262;
        while (scanlines-- > 0)
        {
            ppu_run(1);
            cpu_run(1364 / 12); // 1 scanline
        }
    }
}

int nes_palette(int i){
    pal color = palette[i];
    int red = color.r * 7.0 / 0xFF;
    int green = color.g * 7.0 / 0xFF;
    int blue = color.b * 3.0 / 0xFF;
    return COLOR(red, green, blue);
}

void draw_nes_pallete(int size){
  int j = 0;
  int i = 0;
  for (int idx = 0; idx < 64; ++idx){
    int x = i * size;
    int y = j * size;

    if(x > (SCREEN_WIDTH - size)){
        j++;
        y = j * size;
        i = 0;
        x = 0;
    }

    char buff[100];
       
    setCursor(x,y);
    fillRect(x, y, size, size, nes_palette(idx));
    drawRect(x, y, size, size, 0);
    print(itoa(idx, buff, 10 ));
    // write(color);
    i++;
  }
}

void fce_update_screen()
{
    int idx = ppu_ram_read(0x3F00);
    pal bgc = palette[idx];
    nes_set_bg_color(idx);

    int i;
    if (ppu_shows_sprites()) {
        for (i = 0; i < bbg.size; i ++) {
            nes_draw_pixel(bbg.buf + i);
        }
    }
    
    if (ppu_shows_background()) {
        for (i = 0; i < bg.size; i ++) {
            nes_draw_pixel(bg.buf + i);
        }
    }
    
    if (ppu_shows_sprites()) {
        for (i = 0; i < fg.size; i ++) {
            nes_draw_pixel(fg.buf + i);
        }
    }
    pixbuf_clean(bbg);
    pixbuf_clean(bg);
    pixbuf_clean(fg);
}

