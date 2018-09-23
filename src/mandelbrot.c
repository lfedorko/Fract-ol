/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:12:24 by lfedorko          #+#    #+#             */
/*   Updated: 2018/07/03 20:12:25 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void init_mandelbrot(t_map *map)
{

	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W + 200, WIN_H, "Fract'ol");
	map->n_i = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->image = mlx_get_data_addr(map->n_i, &(map->b_p_p), &(map->s_l), &(map->end));
	map->f->iter = 9;
	map->f->zoom = 1;
	map->f->re_area[0] = -2;
	map->f->re_area[1] = -0.5;
	map->f->im_area[0] = -2;
	map->f->im_area[1] = map->f->im_area[0] + (map->f->re_area[1]-map->f->re_area[0]) * WIN_H/WIN_W;
	map->f->add[0] = (map->f->re_area[1] - map->f->re_area[0]) / (WIN_W - 1);
	map->f->add[1] = (map->f->im_area[1] - map->f->im_area[0]) / (WIN_H - 1);
}

void draw_mandelbrot(t_map *map, int x, int y, float *c)
{
	float	tmp[2];
	int		i;
	float	re;
	float	im;
	int		pos;

	i = -1;
 	re = 0;
	im = 0;

	while (++i < map->f->iter && ((pow(re, 2) + pow(im, 2)) < 4))
	{
		tmp[0] = re;
		tmp[1] = im;
		re = pow(tmp[0], 2) - pow(tmp[1], 2) + c[0];
		im = 2 * tmp[0] * tmp[1] + c[1];
	}
	if (i < map->f->iter && pos >= 0 && pos < WIN_H * WIN_W * 4) 
	{
		pos = x * 4 + y * map->s_l;
		map->image[pos] = 0;
		map->image[pos + 1] = i * 6;
		map->image[pos + 2] = i * 6 % 128;
	}
}
