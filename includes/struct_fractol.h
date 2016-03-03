/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fractol.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:22:29 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/03 08:33:40 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FRACTOL_H
# define STRUCT_FRACTOL_H

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_julia
{
	t_complex		c;
	t_complex		new;
	t_complex		old;
}					t_julia;

typedef struct		s_coord
{
	uint16_t		x;
	uint16_t		y;
}					t_coord;

typedef struct  	s_env
{
    void        	*mlx;
    void        	*win;
    t_img           *img;
    int             (*fractal[2])(t_coord pixel, void *data);
    void            (*init_data[2])(void *);
}               	t_env;
#endif
