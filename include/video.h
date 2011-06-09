#ifndef VIDEO_H_
#define VIDEO_H_

#include <nds.h>
#include <cstdio>

#define Color				u16

// Screen resolution
#define SCREEN_WIDTH		256
#define SCREEN_HEIGHT		192
#define SCREEN_PIXEL_COUNT	SCREEN_WIDTH * SCREEN_HEIGHT

// Backgrounds
#define MAIN_BACKGROUND		((Color*)BG_BMP_RAM(0))
#define MAIN_LAYER			((Color*)BG_BMP_RAM(6))

#define BACKGROUND_SIZE		SCREEN_PIXEL_COUNT*2 // (256 * 192 pixels) * 2 byte per pixel

void create_buffers();
void delete_buffers();
void copy_buffers();
void init_displays();
void init_backgrounds();
void init_video();

#endif
