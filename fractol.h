/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:26:07 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/12 14:26:11 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_H 600
# define WIN_W 600
# define MAX_ITER 10000
# define THR 8
# define WIN_SIZE
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <unistd.h>

typedef struct	s_fractol
{
	int			iter;
	double		j[2];
	double		re_area[2];
	double		im_area[2];
	double		add[2];
	int			pause;
}				t_fractol;

typedef struct	s_map
{
	int			fractol;
	void		*mlx;
	void		*win;
	char		*image;
	void		*n_i;
	int			s_l;
	int			b_p_p;
	int			end;
	int			b_end;
	int			begin;
	void		(*fract)(struct s_map *, int, int, double *);
	t_fractol	*f;
}				t_map;

/*
** libft function
*/
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			show_menu(t_map *map);
void			free_func(t_map *map);

/*
** key.c
*/
void			move_image(int k, t_map *map);
int				mouse_move_hook(int x, int y, t_map *map);
int				mouse_exit(t_map *map);
int				key_exit(int k, t_map *map);

/*
** fract.c
*/
void			julia_draw(t_map *map, int x, int y, double *c);
void			draw_mandelbrot(t_map *map, int x, int y, double *c);
void			ship_draw(t_map *map, int x, int y, double *c);

/*
** mouse.c
*/
void			apply_zoom(t_map *map, int x, int y, double zoom);
int				move_with_mouse(int x, int y, t_map *map);
int				zoom_with_mouse(int key, int x, int y, t_map *map);

/*
** draw.c
*/
void			draw(t_map *map);
void			init_fractol(t_map *map);
void			redraw(t_map *map);

/*
** init.c
*/
void			init_fractol(t_map *map);
void			init_param(t_map *map);
void			init_map(t_map *map);

#endif
