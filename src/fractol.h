#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_H 600
# define WIN_W 800
# define THR 8
# define WIN_SIZE
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h> 
# include <math.h>
# include <pthread.h>
# include <unistd.h>

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
}				t_color;

/*
** value of area 0 - min 1 - max
**  others 0 - re 1 -im
*/
typedef struct	s_fractol
{
	int			fract;
	float		zoom;
	int			iter;
	int			x; 
	int			y;
	float		c[2]; 
	float		re_area[2];
	float		im_area[2];
	float 		add[2];
	float		move[2];
    int			pause;
}				t_fractol;

typedef struct	s_map
{
	int			thread;
	void		*mlx;
	void		*win;
	char		*image;
	void		*n_i;
	int			s_l;
	int			b_p_p;
	int			end;
    void        (*fract)(struct s_map *, int, int);
	t_fractol 	*f;
	t_color		*color;
}				t_map;

typedef struct	s_thread
{
	t_map		*map;
	int			begin;
	int			end;
	pthread_t	thread;
}				t_thread;

void	ft_bzero(void *s, size_t n);
char			*ft_itoa(int n);
size_t		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);

void		show_menu(t_map* map);
void		free_func(t_map *map);
/*
** key_option.c
*/
void		move_image(int k, t_map *map);
int			mouse_move_hook(int x, int y, t_map *map);
int			mouse_exit(t_map *map);
int			key_exit(int k, t_map *map);
int			move_with_mouse(int x, int y, t_map *map);
int			zoom_with_mouse(int key, int x, int y, t_map *map);

/*
** julia.c
*/
void			init_julia(t_map *map);
void	        julia_draw(t_map *map, int x, int y);
/*
** mandelbrot.c
*/
void			init_mandelbrot(t_map *map);
void			draw_mandelbrot(t_map *map, int x, int y);
/*
** burning_ship.c
*/
void			init_ship(t_map *map);
void			ship_draw(t_map *map, int x, int y);

/*
** draw_options.c
*/
void			set_color(t_map *map, int x, int y);
void  			draw(t_map *map);
void			init_fractol(t_map *map);
void			change_iter(t_map *map);
void 			redraw(t_map *map);

#endif