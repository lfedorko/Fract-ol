#include "fractol.h"

void 	*handle_thread(void *part)
{
	int			x;
	int			y;
	t_thread	*p;


	p = (t_thread *)part;
	x = p->begin - 1;
   	while (++x < p->end)
	{
		y = -1;
		while (++y < WIN_H)
			p->map->fract(p->map, x, y);
	}
	return (NULL);
}

void free_func(t_map *map)
{
	free(map->f);
	free(map->color);
	free(map);
}

void  draw(t_map *map)
{
	t_thread	*zone;
	int			i;
	int			part;

	i = -1;
	part = WIN_W / THR;
    zone = (t_thread *)malloc(sizeof(t_thread) * THR);
	while (++i < THR)
	{
		zone[i].map = map;
		zone[i].begin = i * part;
		zone[i].end = zone[i].begin + part;
		pthread_create(&zone[i].thread, NULL, (void *)handle_thread, (void *)(&zone[i]));
	}
	i = -1;
	while (++i < THR)
		pthread_join(zone[i].thread, NULL);
	free(zone);
}
void	process(int n)
{
	t_map		*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	map->f = (t_fractol *)malloc(sizeof(t_fractol));
	map->color = (t_color *)malloc(sizeof(t_color));
	map->f->fract = n;
	map->f->pause = 0;
	init_fractol(map);
	mlx_put_image_to_window(map->mlx, map->win, map->n_i, 200, 0);
	mlx_hook(map->win, 17, 1L << 17, mouse_exit, map);
	mlx_hook(map->win, 2, 0, key_exit, map);
	if (map->f->fract == 3)
		mlx_hook(map->win, 6, (1L << 6), mouse_move_hook, map);
	show_menu(map);
	mlx_loop(map->mlx);
	free_func(map);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) == 1 &&
		(*argv[1] > '0' && *argv[1] < '5'))
		process(*argv[1] - 48);
	else
	{
		write(1, "Invalid argument\n", 17);
		write(1, "./fractol <fractol-number>\n", 27);
		write(1, "1 - mandelbrot\n2 - ship\n3 - NaN\n4 - julia\n", 47);
	}
	return (0);
}