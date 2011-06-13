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

void draw_line_between_rope_segments(Buffer* background, Color color, RopeSegment* segment1, RopeSegment* segment2)
{
	u8 x1, y1, x2, y2;

	if (segment1->x - 2 < 0)
		x1 = 2;
	else if (segment1->x + 3 > 256)
		x1 = 256 - 3;
	else
		x1 = segment1->x;

	if (segment1->y - 2 < 0)
		y1 = 2;
	else
		y1 = segment1->y;

	if (segment2->x - 2 < 0)
		x2 = 2;
	else if (segment2->x + 3 > 256)
		x2 = 256 - 3;
	else
		x2 = segment2->x;

	if (segment2->y - 2 < 0)
		y2 = 2;
	else
		y2 = segment2->y;

	draw_line(background, x1, y1, x2, y2, color); 
}

void draw_rope_segment(Buffer* background, RopeSegment* segment, Color color)
{
	u8 x, y;

	if (segment->x - 2 < 0)
		x = 0;
	else if (segment->x + 3 > 256)
		x = 256 - 5;
	else
		x = segment->x - 2;

	if (segment->y - 2 < 0)
		y = 0;
	else
		y = segment->y - 2;

	fill_rect(background, x, y, 5, 5, color);
}

void draw_rope(Buffer* background, Rope* rope)
{
	LinkedList * segment = rope->rope_segment_list;

	if(segment == NULL)
		return;

	while (segment->next != NULL) {
		segment = segment->next;
		draw_rope_segment(background, (RopeSegment*)segment->data, rope->color);
		if (segment->next != NULL)
			draw_line_between_rope_segments(background, rope->color, (RopeSegment*)segment->data, (RopeSegment*)segment->next->data);
	}
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