/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:37:12 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/12 17:37:13 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		zoom_with_mouse(int key, int x, int y, t_map *map)
{
	if ((key == 4 || key == 5) && (x < WIN_W))
	{
		if (key == 4)
		{
			apply_zoom(map, x, y, 1.1);
		}
		else if (key == 5)
		{
			apply_zoom(map, x, y, 0.9);
		}
		redraw(map);
	}
	return (0);
}

int		mouse_move_hook(int x, int y, t_map *map)
{
	if (map->f->pause)
	{
		map->f->j[0] = ((double)((x - WIN_W) / 2) / WIN_W);
		map->f->j[1] = ((double)((y - WIN_H) / 2) / WIN_H);
		redraw(map);
	}
	return (0);
}

void	apply_zoom(t_map *map, int x, int y, double zoom)
{
	double re;
	double im;

	im = (double)(map->f->im_area[1] - (double)y * (map->f->im_area[1]
		- map->f->im_area[0]) / (WIN_H - 1));
	re = (double)map->f->re_area[0] + (double)x * (map->f->re_area[1]
		- map->f->re_area[0]) / (WIN_W - 1);
	map->f->re_area[0] = ((map->f->re_area[0] - re) * zoom) + re;
	map->f->re_area[1] = ((map->f->re_area[1] - re) * zoom) + re;
	map->f->im_area[0] = ((map->f->im_area[0] - im) * zoom) + im;
	map->f->im_area[1] = (double)(map->f->im_area[0] + (map->f->re_area[1])
		- map->f->re_area[0]) * (WIN_H / WIN_W);
}
