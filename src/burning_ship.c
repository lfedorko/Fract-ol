/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:10:37 by lfedorko          #+#    #+#             */
/*   Updated: 2018/07/03 20:10:38 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void init_ship(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W + 200, WIN_H, "Fract'ol");
	map->n_i = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->image = mlx_get_data_addr(map->n_i, &(map->b_p_p), &(map->s_l), &(map->end));
	map->f->iter = 9;
	map->f->zoom = 1;
	map->f->move[0] = 0.5;
	map->f->move[1] = -0.5;
}

void	ship_draw(t_map *map, int x, int y)
{
	float	tmp;
	int		i;
	float	c[2];
	float	re;
	float	im;
	int		pos;

	i = -1;
	c[0] = 1.5 * (x - WIN_W / 2) / (0.5 * map->f->zoom * WIN_W) - 1 + map->f->move[0];
	c[1] = (y - WIN_H / 2) / (0.5 * map->f->zoom * WIN_H) + map->f->move[1];
	re = c[0];
	im = c[1];
	while (++i < map->f->iter && ((pow(re, 2) + pow(im, 2)) < 4))
	{
		tmp = im;
		im = fabs(re * im + re * im + c[1]);
		re = fabs(re * re - pow(tmp, 2) + c[0]);
	}
	if (i < map->f->iter && pos >= 0 && pos < WIN_H * WIN_W * 4) 
	{
		pos = x * 4 + y * map->s_l;
		map->image[pos] = 0;
		map->image[pos + 1] = i * 6;
		map->image[pos + 2] = i * 6 % 128;
	}
}
