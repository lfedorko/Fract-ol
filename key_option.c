#include "fractol.h"

int		mouse_exit(t_map *map)
{
	//ft_memdel(map);
	exit(1);

}

int		key_exit(int k,t_map *map)
{
	
	if (k == 53)
		exit(0);
	if (k == 24)
	{
		if (map->f->iter < 20)
			map->f->iter += 1;
		redraw(map);
	}
	if (k == 27)
	{
		if (map->f->iter > 2)
		{
			map->f->iter -= 1;
			redraw(map);
		}
	}
	if (k == 123 || k == 124 || k == 125 || k == 126)
		move_image(k, map);
 	if (k == 49)
		map->f->pause = !map->f->pause;
	return (1);
}

void move_image(int k, t_map *map)
{
	if (k == 123)
		map->f->move[0] += 0.2;
	else if (k == 124)
		map->f->move[0] -= 0.2;
	else if (k == 125)
		map->f->move[1] -= 0.2;
	else if (k == 126)
		map->f->move[1] += 0.2;
	redraw(map);
}

int		zoom_with_mouse(int key, int x, int y, t_map *map)
{
	x = y;
	if (key == 4)
	{
		map->f->zoom /= 1.1;
		map->f->move[0] += -((WIN_W/ 2 - map->add_x)) / 1000 / map->f->zoom;
		map->f->move[1] += -((WIN_H / 2 - map->add_y)) / 1000 / map->f->zoom;
	}
	if (key == 5)
	{
		map->f->zoom *= 1.1;
		map->f->move[0] += -((WIN_H / 2 - map->add_x) / 1000) / map->f->zoom;
		map->f->move[1] += -((WIN_W / 2 - map->add_y) / 1000) / map->f->zoom;
	}
	redraw(map);
	return (0);
}

int		mouse_move_hook(int x, int y, t_map *map)
{
	if (map->f->pause)
	{
		map->f->c[0] = ((float)((x - WIN_W) / 2)/ WIN_W) * 0.84;
		map->f->c[1] = ((float)((y - WIN_H) / 2) / WIN_H) * 0.84;
		redraw(map);
	}
	return (0);
}