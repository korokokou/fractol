/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourUser <YourMail>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:31:48 by YourUser          #+#    #+#             */
/*   Updated: 2016/02/26 22:48:04 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCREEN_W 512 
# define SCREEN_H 512 

# include <stdlib.h>
# include <mlx.h>

# include "struct_fractol.h"

t_img	*new_image(void *mlx);
void	reset_image(t_img *img);
void	add_point(t_img *img, int x, int y, int color_calc);

#endif
