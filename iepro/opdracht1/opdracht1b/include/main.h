#ifndef MAIN_H_
#define MAIN_H_

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

PrintConsole top_screen;
PrintConsole bottom_screen;

u8 *vert_diag_scroll[21];
u8 *horizontal_scroll[28];

enum Color
{
	black=30,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white
};

enum Direction
{
	horizontal,
	vertical,
	diagonal,
	vert_diag
};

inline void sleep(u32 cycles){u32 i = 0;for(i = 0; i < cycles; i++){swiWaitForVBlank();}};
inline void set_position(u8 rows, u8 cols){iprintf("\x1b[%i;%if", rows, cols);}
inline void set_font_color(u8 cShellColor){if(cShellColor>29&&cShellColor<38)iprintf("\x1b[%im",cShellColor);}
inline u8 get_random_c_shell_color(){return (rand() % 7 + 31);}

void prepare_screens();
void reset_screens();
void loop();

#endif