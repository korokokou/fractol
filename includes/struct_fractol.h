/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fractol.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:22:29 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/19 17:12:34 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FRACTOL_H
# define STRUCT_FRACTOL_H

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_burningsheep
{
	t_complex		c;
	t_complex		new;
	t_complex		old;
	t_complex		step;
	t_coord			move;
	float			zoom;
}					t_burningsheep;

typedef struct		s_mandelbrot
{
	t_complex		c;
	t_complex		new;
	t_complex		old;
	t_complex		step;
	t_coord			move;
	float			zoom;
}					t_mandelbrot;

typedef struct		s_julia
{
	t_complex		c;
	t_complex		new;
	t_complex		old;
	t_complex		step;
	t_coord			move;
	float			zoom;
}					t_julia;

typedef struct  	s_env
{
    void        	*mlx;
    void        	*win;
	void			*data;
    t_img           *img;
    t_coord			old_pos;
	int             (*fractal[2])(t_coord pixel, void *data);
    void            (*init_data[2])(void **);
	int				motion;
}               	t_env;
#endif
