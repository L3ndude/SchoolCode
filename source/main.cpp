#include <nds.h>
#include <rope.h>

extern Buffer* main_buffer;
extern Buffer* main_layer;

Rope* rope;
bool physics;

void loop()
{
	while(1)
	{
		clear_topscreen();
		
		touchPosition touch;
		touchRead(&touch);
		scanKeys();

		if (keysDown() & KEY_TOUCH)
			add_segment_to_rope(rope, create_rope_segment(touch.px, touch.py, 0, 10));

		if (keysDown() & KEY_START)
			physics = true;

		if(physics)
			give_rope_physics(rope);
		
		copy_buffers();
		swiWaitForVBlank();
	}
}

int main()
{
	init_video();

	fill_background(main_buffer, COLOR_BLACK);

	physics = false;

	rope = create_rope(COLOR_WHITE, new LinkedList);

	loop();

	delete_buffers();

	return 0;
}