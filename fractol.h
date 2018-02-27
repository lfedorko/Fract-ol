#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_H 600
# define WIN_W 800
# define WIN_SIZE
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
}				t_color;

typedef struct	s_fractol
{
	int			fract;
	float		zoom; //зум
	int			iter; // кол-во итераций
	int			x; 
	int			y;
	float		re;
	float		im;
	float		c[2]; 
	float		move[2]; 
}				t_fractol;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	char		*image;
	void		*n_i;
	int			s_l;
	int			b_p_p;
	int			end;
	t_fractol 	*f;
	t_color		*color;
	float		add_x;
	float		add_y;
}				t_map;

typedef struct	s_bres
{
	int			a;
	int			b;
	int			sa;
	int			sb;
	int			x[2];
	int			y[2];
	int			p[2];
}				t_bres;


void		julia_draw(t_map *map, t_fractol *f);

/*
** key_option.c
*/
void		move_image(int k, t_map *map);
int			mouse_move(int x, int y, t_map *map);
int			mouse_exit(t_map *map);
int			key_exit(int k, t_map *map);
int			move_with_mouse(int x, int y, t_map *map);

/*
** init.c
*/
void			init_img_win(t_map *map);

/*
** mandelbrot.c
*/
void			draw_mandelbrot(t_map *map, t_fractol *f);
/*
** burning_ship.c
*/
void			ship_draw(t_map *map, t_fractol *f);
/*
** triangle.c
*/
void			triangle_draw(t_map *map, t_fractol *f);
/*
** draw_options.c
*/
void			set_color(t_map *map, int x, int y);
void			draw_fractol(t_map *map);
void			change_iter(t_map *map);
void 			redraw(t_map *map);
/*
**
*/
void			bresenham(t_map *map, t_bres *bres);

#endif