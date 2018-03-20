#include "fractol.h"

void redraw(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	ft_bzero(map->image, WIN_H * WIN_W * 4);
	draw(map);
	show_menu(map);
	mlx_put_image_to_window(map->mlx, map->win, map->n_i, 200, 0);
}

void	set_color(t_map *map, int x, int y)
{
	int	pos;

	pos = (x) * 4 + (y) * map->s_l;
	if (pos >= 0 && pos < WIN_H * WIN_W * 4)
	{
		map->image[pos] = map->color->r;
		map->image[pos + 1] = map->color->g;
		map->image[pos + 2] = map->color->b;
	}
}

void	init_fractol(t_map *map)
{
		if (map->f->fract == 1)
			init_mandelbrot(map);
		// else if (map->f->fract == 2)
		// 	init_ship(map);
		// else if (map->f->fract == 4)
		// 	init_julia(map);
		draw(map);
}

void	show_menu(t_map* map)
{
	mlx_string_put(map->mlx, map->win, 5, 5,  0xFFFFFF, "Fractal\n");
	mlx_string_put(map->mlx, map->win, 5, 25, 0xFFFFFF, "Iteration:");
	mlx_string_put(map->mlx, map->win, 150, 25, 0xFFFFFF, ft_itoa(map->f->iter));
	if (map->f->pause == 1)
		mlx_string_put(map->mlx, map->win, 5, 500, 0xFF, "PAUSE");
	else
		mlx_string_put(map->mlx, map->win, 5, 500, 0xFFFF, "     ");
}
