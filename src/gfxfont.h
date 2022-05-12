// Font structures for newer Adafruit_GFX (1.1 and later).
// Example fonts are included in 'Fonts' directory.
// To use a font in your Arduino sketch, #include the corresponding .h
// file and pass address of GFXfont struct to setFont().  Pass NULL to
// revert to 'classic' fixed-space bitmap font.

#ifndef _GFXFONT_H_
#define _GFXFONT_H_

/// Font data stored PER GLYPH
typedef struct {
  u16 bitmapOffset; ///< Pointer into GFXfont->bitmap
  u8 width;         ///< Bitmap dimensions in pixels
  u8 height;        ///< Bitmap dimensions in pixels
  u8 xAdvance;      ///< Distance to advance cursor (x axis)
  i8 xOffset;        ///< X dist from cursor pos to UL corner
  i8 yOffset;        ///< Y dist from cursor pos to UL corner
} GFXglyph;

/// Data stored for FONT AS A WHOLE
typedef struct {
  u8 *bitmap;  ///< Glyph bitmaps, concatenated
  GFXglyph *glyph;  ///< Glyph array
  u16 first;   ///< ASCII extents (first char)
  u16 last;    ///< ASCII extents (last char)
  u8 yAdvance; ///< Newline distance (y axis)
} GFXfont;

#endif // _GFXFONT_H_
