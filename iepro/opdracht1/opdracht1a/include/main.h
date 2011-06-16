#ifndef MAIN_H_
#define MAIN_H_

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i = 0;

inline void sleep(int cycles){for(i = 0; i < cycles; i++){swiWaitForVBlank();}};
inline void setPosition(int rows, int cols){iprintf("\x1b[%i;%if", rows, cols);}
inline void setFontColor(int cShellColor){if(cShellColor>29&&cShellColor<38)iprintf("\x1b[%im",cShellColor);}
inline int getRandomCShellColor(){return (rand() % 7 + 31);}

void resetScreens();
void init_video();
int main();

#endif