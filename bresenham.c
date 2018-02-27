#include "fractol.h"

static void	bresenham1(t_map *map, t_bres *bres)
{
	int f;
	int x;
	int y;

	f = 0;
	x = bres->x[0];
	y = bres->y[0];
	while (x != bres->x[1] || y != bres->y[1])
	{
		f = f + bres->b * bres->sb;
		if (f > 0)
		{
			f = f - bres->a * bres->sa;
			x = x - bres->sb;
		}
		y = y + bres->sa;
		if (x < WIN_W && x > 0 && y < WIN_H && y > 0)
			set_color(map, x, y);
	}
}

static void	bresenham2(t_map *map, t_bres *bres)
{
	int f;
	int x;
	int y;

	f = 0;
	x = bres->x[0];
	y = bres->y[0];
	while (x != bres->x[1] || y != bres->y[1])
	{
		f = f + bres->a * bres->sa;
		if (f > 0)
		{
			f = f - bres->b * bres->sb;
			y = y + bres->sa;
		}
		x = x - bres->sb;
		if (x < WIN_W && x > 0 && y < WIN_H && y > 0)
			set_color(map, x, y);
	}
}

void		bresenham(t_map *map, t_bres *bres)
{
	bres->a = bres->y[1] - bres->y[0];
	bres->b = bres->x[0] - bres->x[1];
	bres->sa = (bres->a < 0 ? -1 : 1);
	bres->sb = (bres->b < 0 ? -1 : 1);
	if (fabs((float)bres->a) < fabs((float)bres->b))
		bresenham2(map, bres);
	else
		bresenham1(map, bres);
}