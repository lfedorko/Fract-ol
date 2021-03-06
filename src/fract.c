/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:38:37 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/11 20:38:38 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandelbrot(t_map *map, int x, int y, double *c)
{
	double	tmp[2];
	int		i;
	double	re;
	double	im;
	int		pos;

	i = -1;
	re = 0;
	im = 0;
	while (++i < map->f->iter)
	{
		tmp[0] = re * re;
		tmp[1] = im * im;
		if (tmp[0] + tmp[1] > 4)
			break ;
		im = 2 * re * im + c[1];
		re = tmp[0] - tmp[1] + c[0];
	}
	pos = x * 4 + y * map->s_l;
	if (i < map->f->iter && pos >= 0 && pos < WIN_H * WIN_W * 4)
	{
		map->image[pos] = i * 6;
		map->image[pos + 1] = i * 6 % 64;
	}
}

void	ship_draw(t_map *map, int x, int y, double *c)
{
	double	tmp[2];
	int		i;
	double	re;
	double	im;
	int		pos;

	re = 0;
	im = 0;
	i = -1;
	while (++i < map->f->iter)
	{
		tmp[0] = re * re;
		tmp[1] = im * im;
		if (tmp[0] + tmp[1] > 4)
			break ;
		im = fabs(2 * re * im) + (-2.0 * c[1]);
		re = tmp[0] - tmp[1] + c[0];
	}
	pos = x * 4 + y * map->s_l;
	if (i < map->f->iter && pos >= 0 && pos < WIN_H * WIN_W * 4)
	{
		map->image[pos] = i * 6;
		map->image[pos + 2] = i * 6 % 128;
	}
}

void	julia_draw(t_map *map, int x, int y, double *c)
{
	double	tmp[2];
	int		i;
	double	re;
	double	im;
	int		pos;

	i = -1;
	re = c[0];
	im = c[1];
	while (++i < map->f->iter)
	{
		tmp[0] = re * re;
		tmp[1] = im * im;
		if (tmp[0] + tmp[1] > 4)
			break ;
		im = 2 * re * im + map->f->j[1];
		re = tmp[0] - tmp[1] + map->f->j[0];
	}
	pos = x * 4 + y * map->s_l;
	if (i < map->f->iter && pos >= 0 && pos < WIN_H * WIN_W * 4)
	{
		map->image[pos + 1] = i * 6;
		map->image[pos + 2] = i * 6 % 64;
	}
}
