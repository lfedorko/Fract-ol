#include "fractol.h"


void init_ship(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_W + 200, WIN_H, "Fract'ol");
	map->n_i = mlx_new_image(map->mlx, WIN_W, WIN_H);
	map->image = mlx_get_data_addr(map->n_i, &(map->b_p_p), &(map->s_l), &(map->end));
	map->f->iter = 9;
	map->f->zoom = 1;
	map->f->move[0] = 0;
	map->f->move[1] = -0.5;
}

void	ship_draw(t_map *map, int x, int y)
{
	float	tmp;
	int		i;
    float   c[2];
    float   re;
    float   im;

    i = 0;
    c[0] = 1.5 * (x - WIN_W / 2) / (0.5 * map->f->zoom * WIN_W) - 1 + map->f->move[0];
    c[1] = (y - WIN_H / 2) / (0.5 * map->f->zoom * WIN_H) + map->f->move[1];
    re = c[0];
    im = c[1];
    while (i < map->f->iter && ((pow(re, 2) + pow(im, 2)) < 4))
    {
        tmp = im;
        im = fabs(re * im + re * im + c[1]);
        re = fabs(re * re - pow(tmp, 2) + c[0]);
        i++;
    }
    if (i < map->f->iter)
    {
        map->color->r = 0;
        map->color->b = i * 6 % 255;
        map->color->g = i * 6 % 255;
        set_color(map, x, y);
    }
}