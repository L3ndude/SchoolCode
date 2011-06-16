#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <nds.h>

enum Color
{
	black=30,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white
};

struct Point
{
	u8 x;
	u8 y;
};

struct Size
{
	u8 width;
	u8 height;
};

struct Area
{
	Point point;
	Size size;
};

#endif