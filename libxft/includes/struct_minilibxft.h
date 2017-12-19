/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_minilibxft.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:22:29 by takiapo           #+#    #+#             */
/*   Updated: 2017/12/12 17:16:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef struct_minilibxft_H
# define struct_minilibxft_H

# include <stdint.h>

typedef struct		s_coord
{
	long				x;
	long				y;
}					t_coord;

typedef	struct		s_line
{
	t_coord			c1;
	t_coord			c2;
}					t_line;

typedef struct		s_color
{
	uint8_t			red;
	uint8_t			green;
	uint8_t			blue;
	uint8_t			trans;
}					t_color;

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
