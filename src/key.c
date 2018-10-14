/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:15:31 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/12 14:15:32 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	}
	if (k == 27)
	{
		if (map->f->iter > 0)
			map->f->iter -= 5;
	}
	if (k == 123 || k == 124 || k == 125 || k == 126)
		move_image(k, map);
	if (k == 49 && map->fractol == 3)
		map->f->pause = !map->f->pause;
	if (k == 15)
		init_param(map);
	redraw(map);
	return (1);
}

void	move_image(int k, t_map *map)
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
		map->f->im_area[0] -= 0.1;
		map->f->im_area[1] -= 0.1;
	}
}
