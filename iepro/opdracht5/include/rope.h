#ifndef _ROPE_H_
#define _ROPE_H_

#include <cstdio>
#include <nds.h>
#include <draw.h>
#include <linkedlist.h>

struct Rope
{
	Color color;
	LinkedList* rope_segment_list;
};

struct RopeSegment
{
	u16 x;
	u16 y;
	s8 fall_speed;
	u8 max_fall_speed;
};

Rope * create_rope(Color color, LinkedList* rope_segment_list);
RopeSegment * create_rope_segment(u16 x, u16 y, s8 fall_speed, u8 max_fall_speed);

void delete_rope_segment(RopeSegment* segment);
void delete_rope(Rope* rope);

void add_segment_to_rope(Rope* rope, RopeSegment* segment);

void draw_rope(Buffer* background, Rope* rope);

void give_rope_segment_physics(RopeSegment* segment);
void give_rope_physics(Rope* rope);

#endif