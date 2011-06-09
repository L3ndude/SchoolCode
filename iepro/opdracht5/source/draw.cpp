#include <draw.h>

inline void draw_pixel(Buffer* background, s16 x, s16 y, Color color)
{
	if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		background[(y * 256) + x] = color;
	}
}

void fill_background(Buffer* background, Color color)
{
	u16 index;

	for(index = 0; index < SCREEN_PIXEL_COUNT; index++)
	{
		background[index] = color;
	}
}

void draw_bitmap(Buffer* background, Buffer* bitmap, s16 x, s16 y, s16 width, s16 height)
{
	s16 y_pos, x_pos;

	for(y_pos = 0; y_pos <  height; y_pos++)
	{
		for(x_pos = 0; x_pos < width; x_pos++)
		{
			draw_pixel(background, x + x_pos, y + y_pos, bitmap[(y_pos * width) + x_pos]);
		}
	}
}

void draw_line(Buffer* background, s16 x_start, s16 y_start, s16 x_end, s16 y_end, Color color)
{
	s16 x, y, error;

    s16 delta_x = (x_end > x_start ? (x = 1, x_end - x_start) : (x = -1, x_start - x_end)) << 1;
    s16 delta_y = (y_end > y_start ? (y = 1, y_end - y_start) : (y = -1, y_start - y_end)) << 1;

    draw_pixel(background, x_start, y_start, color);

    if (delta_x >= delta_y)
    {
        error = delta_y - (delta_x >> 1);

        while (x_start != x_end)
        {
            if (error >= 0)
            {
                if (error || (x > 0))
                {
                	y_start += y;
                    error -= delta_x;
                }
            }

            x_start += x;
            error += delta_y;

            draw_pixel(background, x_start, y_start, color);
        }
    }
    else
    {
        error = delta_x - (delta_y >> 1);

        while (y_start != y_end)
        {
            if (error >= 0)
            {
                if (error || (y > 0))
                {
                	x_start += x;
                    error -= delta_y;
                }
            }

            y_start += y;
            error += delta_x;

            draw_pixel(background, x_start, y_start, color);
        }
    }
}

void draw_thick_line(Buffer* background, s16 x_start, s16 y_start, s16 x_end, s16 y_end, u8 thickness, Color color)
{
	s16 x, y, error;

    s16 delta_x = (x_end > x_start ? (x = 1, x_end - x_start) : (x = -1, x_start - x_end)) << 1;
    s16 delta_y = (y_end > y_start ? (y = 1, y_end - y_start) : (y = -1, y_start - y_end)) << 1;

    draw_pixel(background, x_start, y_start, color);

    if (delta_x >= delta_y)
    {
        error = delta_y - (delta_x >> 1);

        while (x_start != x_end)
        {
            if (error >= 0)
            {
                if (error || (x > 0))
                {
                	y_start += y;
                    error -= delta_x;
                }
            }

            x_start += x;
            error += delta_y;

            fill_rect(background, x_start, y_start, thickness, thickness, color);
        }
    }
    else
    {
        error = delta_x - (delta_y >> 1);

        while (y_start != y_end)
        {
            if (error >= 0)
            {
                if (error || (y > 0))
                {
                	x_start += x;
                    error -= delta_y;
                }
            }

            y_start += y;
            error += delta_x;

            fill_rect(background, x_start, y_start, thickness, thickness, color);
        }
    }
}

void fill_rect(Buffer* background, s16 x, s16 y, u16 width, u16 height, Color color)
{
	s16 x_pos, y_pos;

	for(y_pos = y; y_pos < height + y; y_pos++)
	{
		for(x_pos = x; x_pos < width + x; x_pos++)
		{
			draw_pixel(background, x_pos, y_pos, color);
		}
	}
}
