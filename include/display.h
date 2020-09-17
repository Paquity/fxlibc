#ifndef __LIB_DISPLAY_H__
# define __LIB_DISPLAY_H__

#include <stddef.h>
#include <stdint.h>

// Internal struct used in each draw function
typedef struct display_s
{
	uint32_t vram[256];
	struct font_s *font;
	struct {
		size_t width;
		size_t height;
	} display;

	// Internal pre-calculated value
	int nb_char_width;
} display_t;

// Internal struct used to define font structure object.
// TODO: move me ?
struct font_s
{
	// Bitmap informations
	struct {
		uint8_t width; 
		uint8_t height;
		uint8_t cwidth;
		uint8_t cheight;
		uint8_t *raw;
	} bitmap;

	// Character information
	struct {
		uint8_t width;
		uint8_t height;
	} font;
};

// Internal struct used to draw
// the ASCII character.
struct font_block_s
{
	int16_t height;
	int16_t width;
	struct {
		uint16_t x;
		uint16_t y;
	} bitmap;
	int16_t x;
	int16_t y;
};

// Draw primitives
extern int dopen(display_t *disp, const char *fontname);
extern void dclear(display_t *disp);
extern void dascii(display_t *disp, int row, int colomn, char const c, int mode);
extern size_t dprint(display_t *disp, int x, int y, char const *str, ...);
extern void dscroll(display_t *disp, int line);
extern void dreverse(display_t *disp, int x, int y, int width, int height);
extern void drect(display_t *disp, int x, int y, int width, int height);
extern void dupdate(display_t *disp);

#endif /*__LIB_DISPLAY_H__*/
