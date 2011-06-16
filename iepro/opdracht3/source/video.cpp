#include "video.hpp"
#include "comic.hpp"

PrintConsole top_screen;
extern Comic xkcd;
Color* main_buffer;

void create_buffers()
{
	main_buffer = new Color[SCREEN_PIXEL_COUNT];
}

void delete_buffers()
{
	delete main_buffer;
}

void copy_buffers()
{
	DC_FlushRange(MAIN_BACKGROUND, BACKGROUND_SIZE);
	dmaCopyHalfWords(DMA_CHANNEL, main_buffer, MAIN_BACKGROUND, BACKGROUND_SIZE);
}

void init_displays()
{
	videoSetMode(MODE_5_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	lcdMainOnBottom();
}

void init_backgrounds()
{
	int main_bg3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
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
	while (1)
	{
		consoleSelect(&top_screen);
		consoleClear();
		puts("Made by Lennart Kroes, s1062295");
		scroll_comic( &xkcd, 1 );
		copy_buffers();
		swiWaitForVBlank();
	}
}