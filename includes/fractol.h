/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourUser <YourMail>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:31:48 by YourUser          #+#    #+#             */
/*   Updated: 2016/03/15 17:46:57 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCREEN_W 1024
# define SCREEN_H 768
# define POINTERMOTIONMASK (1L<<6)
# define KEYPRESSMASK (1L<<0)
# define ENTERWINDOWMASK (1L<<4)
# define MOTIONNOTIFY 6 
# define ENTERNOTIFY 7
#define	MAXITERATION 300
# define KEYPRESS 2

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <mlx.h>

# include "minilibxft.h"
# include "struct_fractol.h"
# include "libft.h"

int 	iterate(t_complex new, t_complex old, t_complex c);
void	draw_fractal(t_env *e, void *data);
void	init_julia(t_env *e);
void	init_mandelbrot(t_env *e);
void	delete_coord(t_complex j, t_complex p);
int		abs(int x);
#endif
