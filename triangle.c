#include "fractol.h"

static void		help_bres(t_map *map, t_bres *bres, int *v)
{
	bres->x[0] = v[0];
	bres->x[1] = v[2];
	bres->y[0] = v[1];
	bres->y[1] = v[3];
	bresenham(map, bres);
	bres->x[0] = v[4];
	bres->x[1] = v[0];
	bres->y[0] = v[5];
	bres->y[1] = v[1];
	bresenham(map, bres);
	bres->x[0] = v[4];
	bres->x[1] = v[2];
	bres->y[0] = v[5];
	bres->y[1] = v[3];
	bresenham(map, bres);
}

static void 	sub_triangle_draw(int d, t_bres *bres, int *v, t_map *map)
{
	int			new[6];


	help_bres(map, bres, v);
	help_bres(map, bres, v);
	help_bres(map, bres, v);
	if (d < map->f->iter)
	{
		new[0] = (v[0] + v[2]) / 2 + (v[2] - v[4]) / 2;
		new[1] = (v[1] + v[3]) / 2 + (v[3] - v[5]) / 2;
		new[2] = (v[0] + v[2]) / 2 + (v[0] - v[4]) / 2;
		new[3] = (v[1] + v[3]) / 2 + (v[1] - v[5]) / 2;
		new[4] = (v[0] + v[2]) / 2;
		new[5] = (v[1] + v[3]) / 2;
		sub_triangle_draw(d + 1, bres, new, map);
		new[0] = (v[4] + v[2]) / 2 + (v[2] - v[0]) / 2;
		new[1] = (v[5] + v[3]) / 2 + (v[3] - v[1]) / 2;
		new[2] = (v[4] + v[2]) / 2 + (v[4] - v[0]) / 2;
		new[3] = (v[5] + v[3]) / 2 + (v[5] - v[1]) / 2;
		new[4] = (v[4] + v[2]) / 2;
		new[5] = (v[5] + v[3]) / 2;
		sub_triangle_draw(d + 1, bres, new, map);
		new[0] = (v[0] + v[4]) / 2 + (v[4] - v[2]) / 2;
		new[1] = (v[1] + v[5]) / 2 + (v[5] - v[3]) / 2;
		new[2] = (v[0] + v[4]) / 2 + (v[0] - v[2]) / 2;
		new[3] = (v[1] + v[5]) / 2 + (v[1] - v[3]) / 2;
		new[4] = (v[0] + v[4]) / 2;
		new[5] = (v[1] + v[5]) / 2;
		sub_triangle_draw(d + 1, bres, new, map);
		d++;
	}

}

void 	triangle_draw(t_map *map, t_fractol *f)
{
	t_bres	*bres;
	int		v[6];
	int		new[6];

	v[0] = 10;
	v[1] = WIN_H - 10;
	v[2] = WIN_W - 10;
	v[3] = WIN_H - 10;
	v[4] = WIN_W / 2;
	v[5] = 10;
	bres = (t_bres *)malloc(sizeof(t_bres));
	map->color->r = 0;
	map->color->b = 255;
	map->color->g = 128;
	help_bres(map, bres, v);
	help_bres(map, bres, v);
	help_bres(map, bres, v);

	new[0] = (v[0] + v[2]) / 2;
	new[1] = (v[1] + v[3]) / 2;
	new[2] = (v[0] + v[4]) / 2;
	new[3] = (v[1] + v[5]) / 2;
	new[4] = (v[2] + v[4]) / 2;
	new[5] = (v[3] + v[5]) / 2;
	sub_triangle_draw(0, bres, new, map);
}