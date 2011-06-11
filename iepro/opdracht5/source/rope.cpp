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
	segment = NULL;
}

void delete_rope(Rope* rope)
{
	LinkedList * list = rope->rope_segment_list;
	LinkedList * next;

	do
	{
		next = list->next;
		if (list->data != NULL)
			delete_rope_segment((RopeSegment*)list->data);
		delete_list_element(list);
		list = next;
	}
	while (list != NULL);

	delete rope;
}

void add_segment_to_rope(Rope* rope, RopeSegment* segment)
{
	add_list_element(rope->rope_segment_list, segment);
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

	if(segment == NULL)
		return;

	while (segment->next != NULL) {
		segment = segment->next;
		give_rope_segment_physics((RopeSegment*)segment->data);
	}
}