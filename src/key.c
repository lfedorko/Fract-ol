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
	    mouse_exit(map);
	if (k == 24)
	{
		if (map->f->iter < MAX_ITER)
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
 	if (k == 49 && map->fractol == 3) {
		map->f->pause = !map->f->pause;
		redraw(map);
	}
 	if (k == 15)
 	{
 	    init_param(map);
        redraw(map);
    }
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

void apply_zoom(t_map *map, int x, int y, double zoom)
{
	double re;
	double im;

	im = map->f->im_area[1] - y * (map->f->im_area[1] - map->f->im_area[0]) / (WIN_H - 1);
	re = map->f->re_area[0] + x * (map->f->re_area[1] - map->f->re_area[0]) / (WIN_W - 1);
	map->f->re_area[0] = ((map->f->re_area[0] - re) * zoom) + re;
	map->f->re_area[1] = ((map->f->re_area[1] - re) * zoom) + re;
	map->f->im_area[0] = ((map->f->im_area[0] - im) * zoom) + im;
//	map->f->im_area[1] = ((map->f->im_area[1] - im) * zoom) + im;
    map->f->im_area[1] = map->f->im_area[0] + (map->f->re_area[1] - map->f->re_area[0]) * (WIN_H/ WIN_W);

}


int		zoom_with_mouse(int key, int x, int y, t_map *map)
{

    if (key == 4)
        apply_zoom(map, x, y, 1.1);
    if (key == 5)
       {
            apply_zoom(map, x, y, 0.95);
//            if (map->f->iter < MAX_ITER)
//            {
//                map->f->iter += 2;
//                redraw(map);
//            }
       }
        redraw(map);
    return (0);
}

int		mouse_move_hook(int x, int y, t_map *map)
{
	if (map->f->pause)
	{
	    map->f->j[0] = ((double)((x - WIN_W) / 2)/ WIN_W);
		map->f->j[1] = ((double)((y - WIN_H) / 2) / WIN_H);
		redraw(map);
	}
	return (0);
}
