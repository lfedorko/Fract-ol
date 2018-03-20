#include "fractol.h"


void init_ship(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W + 200, WIN_H, "Fract'ol");
	map->n_i = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->image = mlx_get_data_addr(map->n_i, &(map->b_p_p), &(map->s_l), &(map->end));
	map->f->iter = 9;
	map->f->zoom = 1;
	map->f->move[0] = 0;
	map->f->move[1] = -0.5;
}

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
