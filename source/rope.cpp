#include "rope.h"

Rope * create_rope(Color color, LinkedList* rope_segment_list)
{
	// TO-DO
}

RopeSegment * create_rope_segment(u16 x, u16 y, s8 fall_speed, u8 max_fall_speed)
{
	// TO-DO
}

void delete_rope(Rope* rope)
{
	// TO-DO
}

void delete_rope_segment(RopeSegment* segment)
{
	// TO-DO
}

void add_segment_to_rope(Rope* rope, RopeSegment* segment)
{
	// TO-DO
}

void draw_rope(Rope* rope)
{
	// TO-DO
}

void physics_for_rope(Rope* rope)
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