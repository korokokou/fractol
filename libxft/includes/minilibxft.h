/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibxft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:33:16 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 23:05:56 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBXFT_H
# define MINILIBXFT_H

# include <mlx.h>
# include <stdlib.h>
# include <stdint.h>

# include "struct_minilibxft.h"

t_img		*new_image(void *mlx, int screen_width, int screen_height);
void		reset_image(t_img *img, int screen_width, int screen_height);
void		make_struct_color(int color_in_hex, t_color *color);
void		add_point_int(t_img *img, int x, int y, int color_calc);
t_color		*itoc(int color_in_hex);
int			ctoi(t_color color);

#endif
