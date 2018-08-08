/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:09:54 by lfedorko          #+#    #+#             */
/*   Updated: 2018/07/03 20:09:55 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	julia_draw(t_map *map, int x, int y)
{
	float	tmp[2];
	float	re;
	float	im;
	int		i;
	int		pos;

	i = 0;
	re = 1.5 * (x - WIN_W / 2) / (0.5 * map->f->zoom * WIN_W) + map->f->move[0];
	im = (y - WIN_H / 2) / (0.5 * map->f->zoom * WIN_H) + map->f->move[1];
	while (i < map->f->iter && ((pow(re, 2) + pow(im, 2)) < 4))
	{
		tmp[0] = re;
		tmp[1] = im;
		re = pow(tmp[0], 2) - pow(tmp[1], 2) + map->f->c[0];
		im = 2 * tmp[0] * tmp[1] + map->f->c[1];
		i++;
	}
	if (i < map->f->iter)
	{
		pos = x * 4 + y * map->s_l;
		map->image[pos] = 0;
		map->image[pos + 1] = i * 6;
		map->image[pos + 2] = i * 6 % 128;
	}
}
