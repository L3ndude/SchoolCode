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

void delete_rope_segment(RopeSegment* segment)
{
	delete segment;
	segment = 0;
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

void draw_rope(Buffer* background, Rope* rope)
{
	// TO-DO
}

void give_rope_segment_physics(RopeSegment* segment)
{
	segment->fall_speed += 1;

	if( segment->fall_speed > segment->max_fall_speed )
	{
		segment->fall_speed = segment->max_fall_speed;
	}

	segment->y += segment->fall_speed;

	if( segment->y > 180 )
	{
		segment->y = 180;
		segment->fall_speed *= -1;
		segment->max_fall_speed /= 2;
	}
}

void give_rope_physics(Rope* rope)
{
	LinkedList * segment = rope->rope_segment_list;
	do {
		give_rope_segment_physics((RopeSegment*)segment->data);
		segment = segment->next;
	} while (segment != 0);
}