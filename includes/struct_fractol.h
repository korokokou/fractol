/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fractol.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:22:29 by takiapo           #+#    #+#             */
/*   Updated: 2016/02/26 22:53:31 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FRACTOL_H
# define STRUCT_FRACTOL_H

# include "../libft/includes/libft.h"
# include "fractol.h"


typedef struct  s_env
{
    void        *mlx;
    void        *win;
}               t_env;

typedef struct		s_image
{
	void			*img_ptr;
	void			*mlx;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*data;
}					t_img;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

#endif
