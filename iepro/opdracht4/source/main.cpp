#include "main.hpp"
#include "comic_image.h"
#include "comic2_image.h"
#include "scroll.h"
#include "next.h"

extern Color* main_buffer;
extern Color* sub_buffer;
extern touchPosition touch;

Comic comics[2];
u8 current_comic;

Button scroll;
Button next;

void scroll_comic()
{
	copy_comic_to_buffer(&comics[current_comic], main_buffer);

	u16 height = (comics[current_comic].size / 2) / comics[current_comic].width;

	if (comics[current_comic].width > height) {
		if ( (keysHeld() & KEY_TOUCH) || (keysHeld() & KEY_RIGHT)) {
			if(comics[current_comic].offset < comics[current_comic].width - SCREEN_WIDTH) {
				comics[current_comic].offset += 2;
			}
		} else if (keysHeld() & KEY_LEFT) {
			if(comics[current_comic].offset > 0) {
				comics[current_comic].offset -= 2;
			}
		}
	}
	else
	{
		if ( (keysHeld() & KEY_TOUCH) || (keysHeld() & KEY_DOWN)) {
			if (comics[current_comic].offset < height - SCREEN_HEIGHT) {
				comics[current_comic].offset += 2;
			}
		} else if (keysHeld() & KEY_UP) {
			if(comics[current_comic].offset > 0) {
				comics[current_comic].offset -= 2;
			}
		}
	}
}

void next_comic()
{
	if(keysDown() & KEY_TOUCH) {
		comics[current_comic].offset = 0;
		if(current_comic == 1)
			current_comic = 0;
		else
			current_comic = 1;
	}
	copy_comic_to_buffer(&comics[current_comic], main_buffer);
}

void copy_comic_to_buffer( Comic *comic, Color *buffer ) {
	s16 x_pos, y_pos;

	u16 height = (comic->size / 2) / comic->width;

	for(y_pos = 0; y_pos < SCREEN_HEIGHT; y_pos++)
	{
		for(x_pos = 0; x_pos < SCREEN_WIDTH; x_pos++)
		{
			if (comic->width > height)
				buffer[(y_pos * SCREEN_WIDTH) + x_pos] = comic->image[ ( y_pos * comic->width ) + ( x_pos + comic->offset ) ];
			else
				buffer[(y_pos * SCREEN_WIDTH) + x_pos] = comic->image[ ( ( y_pos + comic->offset ) * comic->width ) + x_pos ];
		}
	}

}

void copy_button_to_buffer( Button * button, Color * buffer) 
{
	s16 x_pos, y_pos;

	u16 height = (button->size / 2) / button->width;

	for(y_pos = 0; y_pos < height; y_pos++)
	{
		for(x_pos = 0; x_pos < button->width; x_pos++)
		{
			buffer[ ( ( y_pos + button->y ) * SCREEN_WIDTH) + ( x_pos + button->x ) ] = button->image[ ( y_pos * button->width ) + x_pos ];
		}
	}

}

void handle_button( Button* button )
{
	copy_button_to_buffer( button, button->buffer);

	// Kijk of er op een knop is gedrukt met touchPosition
	// Als dat het geval is: roep dan de function pointer van de button aan

	touchRead(&touch);

	if( ( touch.px > button->x && touch.px < (button->x + button->width) ) && 
		( touch.py > button->y && touch.py < (button->y + (button->size/button->width)) ) )
	{
		(button->handler)();
	}

}

int main( int argc, const char* argv[] )
{
	init_video();
	current_comic = 0;

	comics[0].image = (Color*)comic_imageBitmap;
	comics[0].width = 954;
	comics[0].size = (u32)comic_imageBitmapLen;
	comics[0].offset = 0;

	comics[1].image = (Color*)comic2_imageBitmap;
	comics[1].width = 256;
	comics[1].size = (u32)comic2_imageBitmapLen;
	comics[1].offset = 0;

	scroll.image = (Color*)scrollBitmap;
	scroll.width = 96;
	scroll.size = (u32)scrollBitmapLen;
	scroll.x = 20;
	scroll.y = 144;
	scroll.handler = scroll_comic;
	scroll.buffer = sub_buffer;

	next.image = (Color*)nextBitmap;
	next.width = 96;
	next.size = (u32)nextBitmapLen;
	next.x = 20+98+20;
	next.y = 144;
	next.handler = next_comic;
	next.buffer = sub_buffer;

	loop();
	delete_buffers();

	return 0;
}