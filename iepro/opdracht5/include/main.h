#ifndef _MAIN_H_
#define _MAIN_H_

#include <nds.h>
#include <rope.h>

void handle_keys_down(u32 keys);
void handle_keys_held(u32 keys);
void handle_keys_up(u32 keys);

void handle_keys();
void loop();
int main();

#endif