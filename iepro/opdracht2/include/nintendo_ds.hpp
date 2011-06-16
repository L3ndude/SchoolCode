#ifndef NINTENDO_DS_H_
#define NINTENDO_DS_H_

#include <nds.h>
#include <cstdio>
#include <cstdlib>
#include "geometry.hpp"

inline void sleep(u32 vblanks){for(u32 i = 0; i < vblanks; i++){swiWaitForVBlank();}};
inline void set_position(u8 rows, u8 cols){printf("\x1b[%i;%if", rows, cols);}
inline void set_font_color(Color cShellColor){printf("\x1b[%im",cShellColor);}
inline u8 get_random_c_shell_color(){return (rand() % 7 + 31);}

void prepare_screens();
void reset_screens();
void loop();

#endif