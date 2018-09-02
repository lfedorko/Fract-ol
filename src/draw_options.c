/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:10:23 by lfedorko          #+#    #+#             */
/*   Updated: 2018/07/03 20:10:24 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

	pos = x * 4 + y * map->s_l;
	if (pos >= 0 && pos < WIN_H * WIN_W * 4)
	{
		map->image[pos] = map->color->r;
		map->image[pos + 1] = map->color->g;
		map->image[pos + 2] = map->color->b;
	}
}

void	init_fractol(t_map *map)
{
		if (map->fractol == 1)
        {
            map->fract= draw_mandelbrot;
            init_mandelbrot(map);
        }
		else if (map->fractol == 2)
        {
            map->fract = ship_draw;
            init_ship(map);
        }
		else if (map->fractol == 3)
        {
            map->fract = julia_draw;
            init_julia(map);
        }
		draw(map);
}

// void	user_interface(t_var *v)
// {
// 	v->x = 25;
// 	v->y = 25;
// 	mlx_draw(map, 188, 213, UI_CLR);
// 	v->y = 237;
// 	mlx_draw(map, 188, 326, v->m);
// 	v->y = WIN_H - 133;
// 	mlx_draw(map 188, (WIN_H - 25), UI_CLR);
// 	v->y = (WIN_H - 65);
// 	v->x = v->len - 1;
// 	mlx_draw(map, (WIN_W - 25), (WIN_H - 25), UI_CLR);
// }

void	show_menu(t_map* map)
{
	mlx_string_put(map->mlx, map->win, 25, 50, 0xFFFF00, "Iteration:");
	mlx_string_put(map->mlx, map->win, 150, 50, 0xFFFFFF, ft_itoa(map->f->iter));
	mlx_string_put(map->mlx, map->win, 40, 400,  0xFFFF00, "Controls:\n");
	mlx_string_put(map->mlx, map->win, 25, 430, 0xFFFFFF,  "[R] - reset");
	mlx_string_put(map->mlx, map->win, 25, 460, 0xFFFFFF,  "[ARROWS] - move");
	mlx_string_put(map->mlx, map->win, 25, 490, 0xFFFFFF,  "[+/-] - iteration");
	if (map->fractol == 3)
		mlx_string_put(map->mlx, map->win, 25, 520, 0xFFFFFF,  "[SPACE] - rotate");
	// if (map->f->pause == 0)
	// 	mlx_string_put(map->mlx, map->win, 25, 500, 0xFF, "PAUSE");

}
