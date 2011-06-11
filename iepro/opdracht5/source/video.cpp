#include <video.h>

PrintConsole top_screen;
Buffer* main_buffer;
Buffer* main_layer;

void create_buffers()
{
	main_buffer = new Buffer[SCREEN_PIXEL_COUNT];
	main_layer = new Buffer[SCREEN_PIXEL_COUNT];
}

void delete_buffers()
{
	delete[] main_buffer;
	delete[] main_layer;
}

void copy_buffers()
{
	dmaCopy(main_buffer, MAIN_BACKGROUND, BACKGROUND_SIZE);
	dmaCopy(main_layer, MAIN_LAYER, BACKGROUND_SIZE);
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

void clear_topscreen()
{
	consoleSelect(&top_screen);
	consoleClear();
	puts("Made by Lennart Kroes, s1062295");
}