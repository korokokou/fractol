/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibxft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:33:16 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/19 14:25:35 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBXFT_H
# define MINILIBXFT_H

# include <mlx.h>
# include <stdlib.h>
# include <stdint.h>

# include "struct_minilibxft.h"

# define ABS(x) ((x)<0 ? -(x) : (x))

int			ctoi(t_color color);
t_color		*itoc(int color_in_hex);
void		make_struct_color(int color_in_hex, t_color *color);
void		add_point_int(t_img *img, int x, int y, int color_calc);
t_img		*new_image(void *mlx, int screen_width, int screen_height);
void		reset_image(t_img *img, int screen_width, int screen_height);
void		add_point_t_color(t_img *img, int x, int y, t_color color_calc);
int			draw_line_int(t_line line, int color, t_img *img);

#endif
