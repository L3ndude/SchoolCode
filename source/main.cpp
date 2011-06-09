#include <nds.h>
#include <rope.h>

extern Buffer* main_buffer;
extern Buffer* main_layer;

Rope* rope;

void loop()
{
	while(1)
	{
		touchPosition touch;
		touchRead(&touch);
		scanKeys();

		if (keysDown() & KEY_TOUCH)
			add_segment_to_rope(rope, create_rope_segment(touch.px, touch.py, 0, 10));
		
		copy_buffers();
		swiWaitForVBlank();
	}
}

int main()
{
	init_video();

	fill_background(main_buffer, COLOR_BLACK);

	rope = create_rope(COLOR_WHITE, new LinkedList);

	loop();

	delete_buffers();

	return 0;
}