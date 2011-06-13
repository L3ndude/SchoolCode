#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <nds.h>
#include <cstdio>

#define Color				u16
#define Buffer				u16

// Screen resolution
#define SCREEN_WIDTH		256
#define SCREEN_HEIGHT		192
#define SCREEN_PIXEL_COUNT	SCREEN_WIDTH * SCREEN_HEIGHT

// Backgrounds
#define MAIN_BACKGROUND		((Buffer*)BG_BMP_RAM(0))
#define MAIN_LAYER			((Buffer*)BG_BMP_RAM(6))

#define BACKGROUND_SIZE		(SCREEN_PIXEL_COUNT * 2)

void create_buffers();
void delete_buffers();
void copy_buffers();
void clear_buffers();
void clear_buffer(Buffer* background);
void init_displays();
void init_backgrounds();
void init_video();
void clear_topscreen();

#endif
