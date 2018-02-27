#include "fractol.h"
void	show_menu(t_map* map)
{
	mlx_string_put(map->mlx, map->win, 5, 5,  0xFFFFFF, "Fractol\n");
	mlx_string_put(map->mlx, map->win, 5, 25, 0xFFFFFF, "Iteration:");
	mlx_string_put(map->mlx, map->win, 150, 25, 0xFFFFFF, ft_itoa(map->f->iter));
	mlx_string_put(map->mlx, map->win, 5, 50, 0xFFFFFF, "x = ");
}

void	process(int n)
{
	t_map		*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	map->f = (t_fractol *)malloc(sizeof(t_fractol));
	map->f->fract = n;
	map->color = (t_color *)malloc(sizeof(t_color));
	init_img_win(map);
	draw_fractol(map);
	mlx_put_image_to_window(map->mlx, map->win, map->n_i, 200, 0);
	mlx_hook(map->win, 17, 1L << 17, mouse_exit, map);
	mlx_hook(map->win, 2, 0, key_exit, map);
	mlx_hook(map->win, 6, 0, move_with_mouse, map);
	show_menu(map);
	//mlx_mouse_hook(map->win, mouse_move, map); //click
	mlx_loop(map->mlx);
//	ft_memdel((void **)map);
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
		write(1, "1 - mandelbrot\n2 - ship\n3 - triangle\n4 - julia\n", 47);
	}
	return (0);
}