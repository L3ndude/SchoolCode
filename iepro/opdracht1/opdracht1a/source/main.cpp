#include "main.h"

int pos_x = rand() % 15 + 1;
int pos_y = rand() % 20;
PrintConsole topScreen;
PrintConsole bottomScreen;
int color = 31;

char sentence[] = "Hello world!";

// Clears the screen and rewrite the "Made by" sentence
void resetScreens(PrintConsole *topScreen, PrintConsole *bottomScreen)
{
			consoleSelect(topScreen);
			consoleClear();
			setPosition(0,0);
			setFontColor(37);
			iprintf("Made by Lennart Kroes, s1062295");
			consoleSelect(bottomScreen);
			consoleClear();
			setPosition(0,0);
			setFontColor(37);
			iprintf("Made by Lennart Kroes, s1062295");
}

// Initializes the hardware and sets up the screen
void init_video()
{
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
    consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);
}

// Main function, not much to tell
int main()
{
	init_video();
	
	resetScreens(&topScreen, &bottomScreen);

	int j = 0;

	while (1)
	{
		setPosition(pos_x, pos_y+j);

		color = getRandomCShellColor(); // get random color
		setFontColor(color); // set color

		iprintf("%c", sentence[j]); // output

		sleep(40);
				
		if (j < 11) {
			j++;
		} else {
			sleep(60);
			resetScreens(&topScreen, &bottomScreen);
			pos_x = rand() % 15 + 1;
			pos_y = rand() % 20;
			j = 0;
			consoleSelect(((rand()%2) == 1)?&bottomScreen:&topScreen);
		}
		

	}

	return 0;
}