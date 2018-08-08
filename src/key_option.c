/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:10:55 by lfedorko          #+#    #+#             */
/*   Updated: 2018/07/03 20:10:56 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int		mouse_exit(t_map *map)
{
	free_func(map);
	exit(1);
}

int		key_exit(int k, t_map *map)
{
	if (k == 53)
		exit(0);
	if (k == 24)
	{
		if (map->f->iter < 200)
			map->f->iter += 1;
		redraw(map);
	}
	if (k == 27)
	{
		if (map->f->iter > 2)
		{
			map->f->iter -= 1;
			redraw(map);
		}
	}
	if (k == 123 || k == 124 || k == 125 || k == 126)
		move_image(k, map);
 	if (k == 49 && map->f->fract == 3)
		map->f->pause = !map->f->pause;
	return (1);
}

void move_image(int k, t_map *map)
{
	if (k == 123)
		map->f->move[0] += 0.2;
	else if (k == 124)
		map->f->move[0] -= 0.2;
	else if (k == 125)
		map->f->move[1] -= 0.2;
	else if (k == 126)
		map->f->move[1] += 0.2;
	redraw(map);
}

int		zoom_with_mouse(int key, int x, int y, t_map *map)
{

	double x_mult, y_mult;
	printf("%d %d\n",x,y);

	if (key == 4)
	{
		x_mult = x * (1 - 0.9);
    	y_mult = y * (1 - 0.9);
		map->f->zoom *= 0.9;
		printf("%f %f\n",x_mult,y_mult);
		map->f->move[0] += (((WIN_W / 2 - x)) / WIN_W )* 0.9 + x_mult;
		map->f->move[1] += (((WIN_H / 2 - y)) / WIN_H) * 0.9 + y_mult;
	}

	redraw(map);
	return (0);
}

int		mouse_move_hook(int x, int y, t_map *map)
{
	if (map->f->pause)
	{
		map->f->c[0] = ((float)((x - WIN_W) / 2)/ WIN_W) * 0.8;
		map->f->c[1] = ((float)((y - WIN_H) / 2) / WIN_H) * 0.8;
		redraw(map);
	}
	return (0);
}
