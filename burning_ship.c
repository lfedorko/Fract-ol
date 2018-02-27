#include "fractol.h"

void	ship_draw(t_map *map, t_fractol *f)
{

	float	tmp;
	int		i;

	f->x = -1;
	while (++f->x  < WIN_W)
	{
		f->y = -1;
		while (++f->y < WIN_H)
		{
			i = 0;
			f->c[0] = 1.5 * (f->x - WIN_W / 2) / (0.5 *f->zoom * WIN_W) - 1 + f->move[0];
			f->c[1] = (f->y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->move[1];
			f->re = f->c[0];
			f->im = f->c[1];
			while (i < f->iter && ((pow(f->re, 2) + pow(f->im, 2)) < 4))
			{
				tmp = f->im;
				f->im = fabs(f->re * f->im + f->re * f->im + f->c[1]);
				f->re = fabs(f->re * f->re - pow(tmp, 2) + f->c[0]);
				i++;
			}
			if (i < f->iter) 
			{
				map->color->r = 0;
				map->color->b = i * 6 % 255;
				map->color->g = i * 6 % 255;
				set_color(map, f->x, f->y);
			}
		}
	}
}
