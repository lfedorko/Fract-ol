#include "fractol.h"

void init_map(t_map *map)
{
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, WIN_W + 200, WIN_H, "Fract'ol");
    map->n_i = mlx_new_image(map->mlx, WIN_W, WIN_H);
    map->image = mlx_get_data_addr(map->n_i, &(map->b_p_p), &(map->s_l), &(map->end));

}

void init_param(t_map *map)
{
    map->f->iter = 10;
    map->f->zoom = 1;
    map->f->re_area[0] = -2.1;
    map->f->re_area[1] = 1.1;
    map->f->im_area[0] = -1.2;
    map->f->im_area[1] = map->f->im_area[0] + (map->f->re_area[1] - map->f->re_area[0]) * WIN_H/ WIN_W;
}

void	init_fractol(t_map *map)
{
    if (map->fractol == 1)
        map->fract= draw_mandelbrot;
    else if (map->fractol == 2)
        map->fract = ship_draw;
    else if (map->fractol == 3)
        map->fract = julia_draw;
    draw(map);
}