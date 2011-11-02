#ifndef COMIC_H_
#define COMIC_H_

#include "nds.h"
#include "video.hpp"

struct Comic
{
	Color * image;
	u16 width;
	u32 size;
	u16 offset;
};

struct Button
{
	Color * image;
	u16 width;
	u32 size;
	u16 x;
	u16 y;
	void (* handler)();
	Color * buffer;
};

void scroll_comic();
void next_comic();
void copy_comic_to_buffer( Comic * comic, Color * buffer );
void copy_button_to_buffer( Button * button, Color * buffer);
void handle_button( Button* button );
Button* create_button( Color * image, u16 width, u32 size, u16 x, u16 y, void (* handler)(), Color * buffer );

/*
** Laat in de methode scroll_comic de offset_x van het plaatje met speed vooruit scrollen 
** Als het plaatje tot het eind is gescrolled, wacht je 1.5 seconden en zet je het plaatje weer terug naar het begin. 
** 
** Laat de methode copy_comic_to_buffer het plaatje kopiëren naar de buffer. 
** 
** Maak in je main een Comic aan met het plaatje van blackboard. 
** Laat het plaatje scrollen met snelheid 1 (gebruik scroll_comic).
*/

#endif