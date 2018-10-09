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
			map->f->iter += 5;
		redraw(map);
	}
	if (k == 27)
	{
		if (map->f->iter > 2)
		{
			map->f->iter -= 5;
			redraw(map);
		}
	}
	if (k == 123 || k == 124 || k == 125 || k == 126)
		move_image(k, map);
 	if (k == 49 && map->fractol == 3)
		map->f->pause = !map->f->pause;
	return (1);
}

void move_image(int k, t_map *map)
{
	if (k == 123)
    {
		map->f->re_area[0] += 0.1;
	    map->f->re_area[1] += 0.1;
    }
    else if (k == 124)
    {
        map->f->re_area[0] -= 0.1;
        map->f->re_area[1] -= 0.1;
    }
    else if (k == 125)
    {
        map->f->im_area[0] += 0.1;
        map->f->im_area[1] += 0.1;
    }
	else if (k == 126)
    {
        map->f->im_area[0] -= 0.02;
        map->f->im_area[1] -= 0.02;
    }
	redraw(map);
}

void applyZoom(t_map *map, float mouseRe, float mouseIm, float zoomFactor)
{
	float re;
	float im;

	im = map->f->im_area[1] - mouseIm * (map->f->im_area[1] - map->f->im_area[0]) / (WIN_H - 1);
	re = map->f->re_area[0] + mouseRe * (map->f->re_area[1] - map->f->re_area[0]) / (WIN_W - 1);
	map->f->re_area[0] = re + ((map->f->re_area[0] - re) * zoomFactor);
	map->f->re_area[1] = re + ((map->f->re_area[1] - re) * zoomFactor);
	map->f->im_area[0] = im + ((map->f->im_area[0] - im) * zoomFactor);
	map->f->im_area[1] = im + ((map->f->im_area[1] - im) * zoomFactor);
}


int		zoom_with_mouse(int key, int x, int y, t_map *map)
{

	if (key == 4)
		applyZoom(map, x, y, 1.1);
	if (key == 5)
	{
		applyZoom(map, x, y, 0.95);
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
