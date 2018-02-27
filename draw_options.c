#include "fractol.h"

void redraw(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	ft_bzero(map->image, WIN_H * WIN_W * 4);
	draw_fractol(map);
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

void	draw_fractol(t_map *map)
{
	if (map->f->fract == 1)
		draw_mandelbrot(map, map->f);
	else if (map->f->fract == 2)
		ship_draw(map, map->f);
	else if (map->f->fract == 3)
		triangle_draw(map, map->f);
	else if (map->f->fract == 4)
		julia_draw(map, map->f);
}



void		change_iter(t_map *map)
{

}