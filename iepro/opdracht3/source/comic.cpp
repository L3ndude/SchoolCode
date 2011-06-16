#include "comic.hpp"
#include "goto.h"

Comic xkcd = {(Color*)gotoBitmap, 708, 0};
extern Color* main_buffer;

// Scrolls given comic with given speed
void scroll_comic( Comic *comic, u8 speed )
{

	if(comic->image_offset == comic->image_width - SCREEN_WIDTH)
	{
		sleep(90);
		comic->image_offset = 0;
	}

	copy_comic_to_buffer(comic, main_buffer);

	if(comic->image_offset == 1)
	{
	//	sleep(90);
	}

	comic->image_offset += speed;
}

// Copies the given comic to the given buffer
void copy_comic_to_buffer( Comic *comic, Color *buffer ) {
	s16 x_pos, y_pos;

	for(y_pos = 0; y_pos < SCREEN_HEIGHT; y_pos++)
	{
		for(x_pos = 0; x_pos < SCREEN_WIDTH; x_pos++)
		{
			buffer[(y_pos * SCREEN_WIDTH) + x_pos] = comic->image[(y_pos * comic->image_width) + (x_pos + comic->image_offset)];
		}
	}

}

int main( int argc, const char* argv[] )
{
	init_video();
	loop();
	delete_buffers();

	return 0;
}