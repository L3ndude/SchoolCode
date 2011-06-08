#include "video.h"

Color* main_buffer;
Color* main_layer;
Color* sub_buffer;

void create_buffers()
{
	main_buffer = new Color[SCREEN_PIXEL_COUNT];
	main_layer = new Color[SCREEN_PIXEL_COUNT];
	sub_buffer = new Color[SCREEN_PIXEL_COUNT];
}

void delete_buffers()
{
	delete[] main_buffer;
	delete[] main_layer;
	delete[] sub_buffer;
}

void copy_buffers()
{
	dmaCopy(main_buffer, MAIN_BACKGROUND, BACKGROUND_SIZE);
	dmaCopy(main_layer, MAIN_LAYER, BACKGROUND_SIZE);
	dmaCopy(sub_buffer, SUB_BACKGROUND, BACKGROUND_SIZE);
}

void init_displays()
{
	// Set up main screen (mode 5 -> two bitmap layers)
	REG_DISPCNT = MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE;

	// Set up sub screen (mode 3 -> one bitmap layer)
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG3_ACTIVE;

	// Map memory banks to the screens
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_BG;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	// Main screen on the bottem
	lcdMainOnBottom();
}

void init_backgrounds()
{
	// Main screen second background (16 bit bitmap -> 256x256 pixels)
	REG_BG2CNT = BG_BMP16_256x256 | BG_BMP_BASE(6) | BG_PRIORITY(0);

	// Set background: no scaling, rotation and offset
	REG_BG2PA = (1 << 8); // Scale X (1.0 = 0)
	REG_BG2PB = 0; // X rotation
	REG_BG2PC = 0; // Y rotation
	REG_BG2PD = (1 << 8); // Scale Y (1.0 = 0)
	REG_BG2X = 0; // X position
	REG_BG2Y = 0; // Y position

	// Main screen second background (16 bit bitmap -> 256x256 pixels)
	REG_BG3CNT = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(1);

	// Set background: no scaling, rotation and offset
	REG_BG3PA = (1 << 8);
	REG_BG3PB = 0;
	REG_BG3PC = 0;
	REG_BG3PD = (1 << 8);
	REG_BG3X = 0;
	REG_BG3Y = 0;

	// Sub screen second background (16 bit bitmap -> 256x256 pixels)
	REG_BG3CNT_SUB = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(0);

	// Set background: no scaling, rotation and offset
	REG_BG3PA_SUB = (1 << 8);
	REG_BG3PB_SUB = 0;
	REG_BG3PC_SUB = 0;
	REG_BG3PD_SUB = (1 << 8);
	REG_BG3X_SUB = 0;
	REG_BG3Y_SUB = 0;
}

void init_video()
{
	init_displays();
	init_backgrounds();
	create_buffers();
}
