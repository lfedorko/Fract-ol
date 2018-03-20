#include "fractol.h"

void init_julia(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W + 200, WIN_H, "Fract'ol");
	map->n_i = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->image = mlx_get_data_addr(map->n_i, &(map->b_p_p), &(map->s_l), &(map->end));
	map->f->iter = 9;
	map->f->zoom = 1;
	map->f->move[0] = 0;
	map->f->move[1] = 0;
	map->f->c[0] = -0.7;
	map->f->c[1] = 0.27;
}

void	julia_draw(t_map *map, t_fractol *f)
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
			f->re = 1.5 * (f->x - WIN_W / 2) / (0.5 * f->zoom * WIN_W) + f->move[0];
			f->im = (f->y - WIN_H / 2) / (0.5 *  f->zoom * WIN_H) + f->move[1];
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