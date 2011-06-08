#ifndef DRAW_H_
#define DRAW_H_

#include <nds.h>
#include "video.h"

#define PIXEL(x)			(x | (1 << 15))

// Predefined colors
#define COLOR_RED			PIXEL(RGB15(31, 0, 0))
#define COLOR_GREEN			PIXEL(RGB15(0, 31, 0))
#define COLOR_BLUE			PIXEL(RGB15(0, 0, 31))
#define COLOR_YELLOW		PIXEL(RGB15(31, 31, 0))
#define COLOR_CYAN			PIXEL(RGB15(0, 31, 31))
#define COLOR_PURPLE		PIXEL(RGB15(31, 0, 31))
#define COLOR_BLACK			PIXEL(RGB15(0, 0, 0))
#define COLOR_WHITE			PIXEL(RGB15(31, 31, 31))
#define COLOR_NONE			0

void draw_pixel(Color*, s16, s16, Color);
void fill_background(Color*, Color);
void draw_bitmap(Color*, Color*, s16, s16, s16, s16);
void draw_line(Color*, s16, s16, s16, s16, Color);
void fill_rect(Color*, s16, s16, u16, u16, Color);
void draw_thick_line(Color*, s16, s16, s16, s16, u8, Color);

#endif
