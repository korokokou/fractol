/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_minilibxft.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:22:29 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 13:48:39 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef struct_minilibxft_H
# define struct_minilibxft_H

# include <stdint.h>

typedef struct		s_color
{
	uint8_t			red;
	uint8_t			green;
	uint8_t			blue;
	uint8_t			trans;
}					t_color;

typedef struct  	s_env
{
    void        	*mlx;
    void        	*win;
}               	t_env;

typedef struct		s_image
{
	void			*img_ptr;
	void			*mlx;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*data;
}					t_img;
#endif
