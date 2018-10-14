/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:34:53 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/11 20:34:54 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	redraw(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	ft_bzero(map->image, WIN_H * WIN_W * 4);
	draw(map);
	show_menu(map);
	mlx_put_image_to_window(map->mlx, map->win, map->n_i, 0, 0);
}

void	show_menu(t_map *map)
{
	char *k;

	k = ft_itoa(map->f->iter);
	mlx_string_put(map->mlx, map->win, 625, 50, 0xFFFF00, "Iteration:");
	mlx_string_put(map->mlx, map->win, 750, 50, 0xFFFFFF, k);
	mlx_string_put(map->mlx, map->win, 640, 400, 0xFFFF00, "Controls:\n");
	mlx_string_put(map->mlx, map->win, 625, 430, 0xFFFFFF, "[R] - reset");
	mlx_string_put(map->mlx, map->win, 625, 460, 0xFFFFFF, "[ARROWS] - move");
	mlx_string_put(map->mlx, map->win, 625, 490, 0xFFFFFF, "[+/-] - iteration");
	if (map->fractol == 3)
		mlx_string_put(map->mlx, map->win, 625, 520, 0xFFFFFF,
		"[SPACE] - rotate");
	if (map->f->pause == 0 && map->fractol == 3)
		mlx_string_put(map->mlx, map->win, 625, 100, 0xFFFFFF, "PAUSE");
	free(k);
}
