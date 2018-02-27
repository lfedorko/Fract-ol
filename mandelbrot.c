#include "fractol.h"

void draw_mandelbrot(t_map *map, t_fractol *f)
{
	float	tmp[2];
	int		i;

	f->x = -1;
	while (++f->x  < WIN_W)
	{
		f->y = -1;
		while (++f->y < WIN_H)
		{
			i = 0;
			f->re = 0;
			f->im = 0;
			f->c[0] = 1.5 * (f->x - WIN_W / 2) / (0.5 *f->zoom * WIN_W) + f->move[0];
			f->c[1] = (f->y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->move[1];
			while (i < f->iter && ((pow(f->re, 2) + pow(f->im, 2)) < 4))
			{
				tmp[0] = f->re;
				tmp[1] = f->im;
				f->re = pow(tmp[0], 2) - pow(tmp[1], 2) + f->c[0];
				f->im = 2 * tmp[0] * tmp[1] + f->c[1];
				i++;
			}
			if (i < f->iter) 
			{
				map->color->r = 0;
				map->color->b = i * 6 % 1;
				map->color->g = i * 6 % 128;
				set_color(map, f->x, f->y);
			}
		}
	}
}
