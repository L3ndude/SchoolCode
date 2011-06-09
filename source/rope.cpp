#include <rope.h>

Rope * create_rope(Color color, LinkedList* rope_segment_list)
{
	Rope * rope = new Rope;

	rope->color = color;
	rope->rope_segment_list = rope_segment_list;

	return rope;
}

RopeSegment * create_rope_segment(u16 x, u16 y, s8 fall_speed, u8 max_fall_speed)
{
	RopeSegment * segment = new RopeSegment;

	segment->x = x;
	segment->y = y;
	segment->fall_speed = fall_speed;
	segment->max_fall_speed = max_fall_speed;

	return segment;
}

void delete_rope(Rope* rope)
{
	do {
		LinkedList * deletable = rope->rope_segment_list;
		rope->rope_segment_list = deletable->next;

		if(rope->rope_segment_list != 0)
			deletable->next->prev = 0;

		delete_rope_segment((RopeSegment*)deletable->data);

		delete deletable;

	} while (rope->rope_segment_list == 0);

	delete rope;
	rope = 0;
}

void delete_rope_segment(RopeSegment* segment)
{
	delete segment;
	segment = 0;
}

void add_segment_to_rope(Rope* rope, RopeSegment* segment)
{
	LinkedList * new_segment = new LinkedList;

	new_segment->prev = 0;
	new_segment->next = rope->rope_segment_list;
	new_segment->data = segment;

	rope->rope_segment_list->prev = new_segment;
	rope->rope_segment_list = new_segment;
}

void draw_rope(Color* background, Rope* rope)
{
	// TO-DO
}

void give_rope_physics(Rope* rope)
{
	// TO-DO
}

/*

rope_segment->speed += 1;

if( rope_segment->speed > rope_segment->max_speed )
{
    rope_segment->speed = rope_segment->max_speed;
}

rope_segment->y += rope_segment->speed;

if( rope_segment->y > 180 )
{
    rope_segment->y = 180;
    rope_segment->speed *= -1;
    rope_segment->max_speed /= 2;
}

*/