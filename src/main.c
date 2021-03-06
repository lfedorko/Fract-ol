/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:21:21 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/12 14:21:23 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_thread(t_map *p)
{
	int			x;
	int			y;
	double		c[2];

	x = p->begin - 1;
	while (++x < p->b_end)
	{
		y = -1;
		c[0] = p->f->re_area[0] + (double)x * p->f->add[0];
		while (++y < WIN_H)
		{
			c[1] = p->f->im_area[1] - (double)y * p->f->add[1];
			p->fract(p, x, y, c);
		}
	}
}

void	free_func(t_map *map)
{
	free(map->f);
	free(map);
}

void	draw(t_map *map)
{
	pthread_t	th[THR];
	int			i;
	int			part;
	t_map		zone[THR];

	i = -1;
	part = WIN_W / THR;
	map->f->add[0] = (map->f->re_area[1] - map->f->re_area[0])
	/ (double)(WIN_W - 1);
	map->f->add[1] = (map->f->im_area[1] - map->f->im_area[0])
	/ (double)(WIN_H - 1);
	while (++i < THR)
	{
		zone[i] = *map;
		zone[i].begin = i * part;
		zone[i].b_end = zone[i].begin + part;
		pthread_create(&th[i], NULL, (void *)handle_thread, (void *)(&zone[i]));
	}
	i = -1;
	while (++i < THR)
		pthread_join(th[i], NULL);
}

void	process(int n)
{
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->f = (t_fractol *)malloc(sizeof(t_fractol));
	map->f->pause = 0;
	map->fractol = n;
	init_map(map);
	init_param(map);
	init_fractol(map);
	mlx_put_image_to_window(map->mlx, map->win, map->n_i, 0, 0);
	mlx_hook(map->win, 17, 1L << 17, mouse_exit, map);
	mlx_hook(map->win, 2, 0, key_exit, map);
	mlx_mouse_hook(map->win, zoom_with_mouse, map);
	if (map->fractol == 3)
		mlx_hook(map->win, 6, (1L << 6), mouse_move_hook, map);
	show_menu(map);
	mlx_loop(map->mlx);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) == 1 &&
		(*argv[1] > '0' && *argv[1] < '4'))
		process(*argv[1] - 48);
	else
	{
		write(1, "Invalid argument\n", 17);
		write(1, "./fractol <fractol-number>\n", 27);
		write(1, "1 - mandelbrot\n2 - ship\n3 - julia\n", 34);
	}
	return (0);
}
