#include "nintendo_ds.hpp"
#include "clock.hpp"

PrintConsole top_screen;
PrintConsole bottom_screen;
extern Clock cclock;
extern Time time1;
extern Time time2;
extern Time time3;
extern Time time4;

// Clears the screen and rewrites the "Made by" sentence on screen
void reset_screens()
{
	Color default_color = yellow;
	consoleSelect(&top_screen);
	consoleClear();
	set_font_color(default_color);
	puts("Made by Lennart Kroes, s1062295\n");
	consoleSelect(&bottom_screen);
	consoleClear();
	set_font_color(default_color);
	puts("Made by Lennart Kroes, s1062295\n");
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

void loop()
{
	while (1)
	{
		reset_screens();

		display_time(&time1);
		display_time(&time2);
		display_time(&time3);
		display_time(&time4);

		update_clock(&cclock);
		sleep(60);
	}
}