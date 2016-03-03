/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:26:20 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 11:28:35 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibxft.h"

t_img		*new_image(void *mlx, int screen_width, int screen_height)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx, screen_width, screen_height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
		&(img->size_line), &(img->endian));
	img->mlx = mlx;
	return (img);
}
