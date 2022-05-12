#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

// #include "types.h"

#include "util.h"
#include "gfxfont.h"



#ifndef pgm_read_byte
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif

/// A generic graphics superclass that can handle all sorts of drawing. At a
/// minimum you can subclass and provide drawPixel(). At a maximum you can do a
/// ton of overriding to optimize. Used for any/all Adafruit displays!

  void Adafruit_GFX_Init(i16 w, i16 h); // Constructor

  /**********************************************************************/
  /*!
    @brief  Draw to the screen/framebuffer/etc.
    Must be overridden in subclass.
    @param  x    X coordinate in pixels
    @param  y    Y coordinate in pixels
    @param color  16-bit pixel color.
  */
  /**********************************************************************/
   void drawPixel(i16 x, i16 y, u16 color);

  // TRANSACTION API / CORE DRAW API
  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
   void startWrite(void);
   void writePixel(i16 x, i16 y, u16 color);
   void writeFillRect(i16 x, i16 y, i16 w, i16 h,
                             u16 color);
   void writeFastVLine(i16 x, i16 y, i16 h, u16 color);
   void writeFastHLine(i16 x, i16 y, i16 w, u16 color);
   void writeLine(i16 x0, i16 y0, i16 x1, i16 y1,
                         u16 color);
   void endWrite(void);

  // CONTROL API
  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
   void setRotation(u8 r);
   void invertDisplay(bool i);

  // BASIC DRAW API


   void drawFastVLine(i16 x, i16 y, i16 h, u16 color);
   void drawFastHLine(i16 x, i16 y, i16 w, u16 color);
   void fillRect(i16 x, i16 y, i16 w, i16 h,
                        u16 color);
   void fillScreen(u16 color);
  // Optional and probably not necessary to change
   void drawLine(i16 x0, i16 y0, i16 x1, i16 y1,
                        u16 color);
   void drawRect(i16 x, i16 y, i16 w, i16 h,
                        u16 color);

  // These exist only with Adafruit_GFX (no subclass overrides)
  void drawCircle(i16 x0, i16 y0, i16 r, u16 color);
  void drawCircleHelper(i16 x0, i16 y0, i16 r, u8 cornername,
                        u16 color);
  void fillCircle(i16 x0, i16 y0, i16 r, u16 color);
  void fillCircleHelper(i16 x0, i16 y0, i16 r, u8 cornername,
                        i16 delta, u16 color);
  void drawTriangle(i16 x0, i16 y0, i16 x1, i16 y1, i16 x2,
                    i16 y2, u16 color);
  void fillTriangle(i16 x0, i16 y0, i16 x1, i16 y1, i16 x2,
                    i16 y2, u16 color);
  void drawRoundRect(i16 x0, i16 y0, i16 w, i16 h,
                     i16 radius, u16 color);
  void fillRoundRect(i16 x0, i16 y0, i16 w, i16 h,
                     i16 radius, u16 color);

  void drawBitmap(i16 x, i16 y, u8 *bitmap, i16 w, i16 h, u16 color, u16 bg);

  void drawXBitmap(i16 x, i16 y, const u8 bitmap[], i16 w,
                   i16 h, u16 color);

  void drawGrayscaleBitmap(i16 x, i16 y, u8 *bitmap, u8 *mask, i16 w, i16 h);

  void drawRGBBitmap(i16 x, i16 y, u16 *bitmap, u8 *mask,
                     i16 w, i16 h);

  void drawChar(i16 x, i16 y, unsigned char c, u16 color,
                u16 bg, u8 size_x, u8 size_y);
  void getTextBounds(const char *string, i16 x, i16 y, i16 *x1,
                     i16 *y1, u16 *w, u16 *h);

  size_t write(u8 c);
  void setTextSize(u8 s);
  void setFont(const GFXfont *f);

  void setCursor(i16 x, i16 y);

  void setTextColor(u16 c);
  // void setTextColor(u16 c, u16 bg);
  void setTextWrap(bool w);
  void cp437(bool x);
  i16 width(void);
  i16 height(void);
  u8 getRotation(void);
  i16 getCursorX(void);
  i16 getCursorY(void);
  void charBounds(unsigned char c, i16 *x, i16 *y, i16 *minx,
                  i16 *miny, i16 *maxx, i16 *maxy);

  void print(char *s);
  void draw_pallete(int size);

#endif // _ADAFRUIT_GFX_H
