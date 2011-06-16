#include "main.h"

u8 sentence[] = "Hello World!";
u8 space = 0x20;

// Clears the screen and rewrites the "Made by" sentence
void reset_screens()
{
	consoleSelect(&top_screen);
	consoleClear();
	set_font_color(cyan);
	iprintf("Made by Lennart Kroes, s1062295");
	consoleSelect(&bottom_screen);
	consoleClear();
	set_font_color(cyan);
	iprintf("Made by Lennart Kroes, s1062295");
}

// Initializes the hardware and sets up the backgrounds
void prepare_screens()
{
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&top_screen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottom_screen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);
}

// Scrolls a given array
void scroll(s8 *start, u8 **scroll_array, u8 *text_array, u8 length_text_array, enum Direction direction) {

	u8 scroll_limit = 20;

	if (direction == horizontal)
		scroll_limit = 27;
	else if (direction == vert_diag)
		scroll_limit = 20;

	for(u8 i = 0; i < (scroll_limit+1); i++)
		scroll_array[i] = &space;

	for (u8 i = 0; i < length_text_array; i++) {
		if ((*start + i) < (scroll_limit+1) && (*start + i) >= 0) {
			scroll_array[*start + i] = &text_array[i];
		}
	}

	*start = *start - 1;

	if((*start + length_text_array) <= 0)
		*start = scroll_limit;
}

// Prints a given array
void print_scroll(u8 **scroll_array, enum Direction direction)
{
	if (direction == horizontal)
	{
		consoleSelect(&bottom_screen);
		set_font_color(white);
		set_position(11, 1);
		for(u8 i = 0; i < 28; i++)
			iprintf("%c", *scroll_array[i]);
	} 
	else if (direction == vertical) 
	{
		consoleSelect(&bottom_screen);
		set_font_color(white);
		for(u8 i = 0; i < 21; i++)
		{
			set_position(2+i, 30);
			iprintf("%c", *scroll_array[i]);
		}
	}
	else if (direction == diagonal)
	{
		consoleSelect(&top_screen);
		set_font_color(white);
		for(u8 i = 0; i < 21; i++)
		{
			set_position(2+i, 4+i);
			iprintf("%c", *scroll_array[i]);
		}
	}
}

void loop()
{
	s8 horizontal_start = 27;
	s8 vert_diag_start = 20;

	while (1)
	{
		reset_screens();

		scroll(&horizontal_start, horizontal_scroll, sentence, (sizeof(sentence)/sizeof(u8)-1), horizontal);
		print_scroll(horizontal_scroll, horizontal);

		scroll(&vert_diag_start, vert_diag_scroll, sentence, (sizeof(sentence)/sizeof(u8)-1), vert_diag);
		print_scroll(vert_diag_scroll, vertical);
		print_scroll(vert_diag_scroll, diagonal);

		sleep(10);

	}
}

int main()
{
	prepare_screens();
	loop();

	return 0;
}