/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourUser <YourMail>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:31:48 by YourUser          #+#    #+#             */
/*   Updated: 2016/03/03 15:08:05 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCREEN_W 768 
# define SCREEN_H 512
# define POINTERMOTIONMASK (1L<<6)
# define KEYPRESSMASK (1L<<0)
# define ENTERWINDOWMASK (1L<<4)
# define MOTIONNOTIFY 6 
# define ENTERNOTIFY 7
# define KEYPRESS 2

# include <stdlib.h>
# include <stdint.h>
# include <mlx.h>

# include "minilibxft.h"
# include "struct_fractol.h"
# include "libft.h"

#endif
