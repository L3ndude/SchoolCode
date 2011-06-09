#include "video.hpp"
#include "main.hpp"

PrintConsole top_screen;
Color* main_buffer;
Color* sub_buffer;
touchPosition touch;
int keys;

extern Comic comics[2];
extern u8 current_comic;
extern Button scroll;
extern Button next;

void create_buffers()
{
	main_buffer = new Color[SCREEN_PIXEL_COUNT];
	sub_buffer = new Color[SCREEN_PIXEL_COUNT];
}

void delete_buffers()
{
	delete[] main_buffer;
	delete[] sub_buffer;
}

void copy_buffers()
{
	dmaCopy(main_buffer, MAIN_BACKGROUND, BACKGROUND_SIZE);
	dmaCopy(sub_buffer, MAIN_LAYER, BACKGROUND_SIZE);
}

void init_displays()
{
	videoSetMode(MODE_5_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankB(VRAM_B_MAIN_BG);

	lcdMainOnBottom();
}

void init_backgrounds()
{
	int main_bg2 = bgInit(2, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgSetPriority(main_bg2, BG_PRIORITY(1));
	int main_bg3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 6, 0);
	bgSetPriority(main_bg3, BG_PRIORITY(0));
	consoleInit(&top_screen, 0, BgType_Text4bpp, BgSize_T_256x256, 31, 0, 0, 1);
	consoleSelect(&top_screen);
	consoleClear();
	puts("Made by Lennart Kroes, s1062295");
}

void init_video()
{
	init_displays();
	init_backgrounds();
	create_buffers();
}


void loop()
{
	//u16 i,j;
	copy_comic_to_buffer(&comics[current_comic], main_buffer);
	while (1)
	{
		scanKeys();
		
		consoleSelect(&top_screen);
		consoleClear();
		puts("Made by Lennart Kroes, s1062295");

		//scroll_comic();

		/*
		for(j = 0; j < SCREEN_HEIGHT; j++)
		for(i = 0; i < SCREEN_WIDTH; i++)
		sub_buffer[(j * SCREEN_WIDTH) + i] = ( RGB15(17,8,28) | (1 << 15) );
		*/

		handle_button( &scroll );
		handle_button( &next );

		if(keysHeld() & KEY_RIGHT)
			scroll_comic();
		if(keysHeld() & KEY_LEFT)
			scroll_comic();
		if(keysHeld() & KEY_UP)
			scroll_comic();
		if(keysHeld() & KEY_DOWN)
			scroll_comic();

		copy_buffers();

		swiWaitForVBlank();
	}
}