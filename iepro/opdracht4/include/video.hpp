#ifndef VIDEO_H_
#define VIDEO_H_

#include <nds.h>
#include <cstdio>
#include <cstdlib>

#define DMA_CHANNEL			3
#define Color				u16

// Screen resolution
#define SCREEN_WIDTH		256
#define SCREEN_HEIGHT		192
#define SCREEN_PIXEL_COUNT	SCREEN_WIDTH * SCREEN_HEIGHT
#define BACKGROUND_SIZE		SCREEN_PIXEL_COUNT * 2	 // (256 * 192 pixels) * 2 byte per pixel

// Backgrounds
#define MAIN_BACKGROUND		((Color*)BG_BMP_RAM(0))
#define MAIN_LAYER			((Color*)BG_BMP_RAM(6))

void create_buffers();
void delete_buffers();
void copy_buffers();
void init_displays();
void init_backgrounds();
void init_video();
void loop();

inline void sleep(u32 vblanks){for(u32 i = 0; i < vblanks; i++){swiWaitForVBlank();}};
inline void set_position(u8 rows, u8 cols){printf("\x1b[%i;%if", rows, cols);}

#endif