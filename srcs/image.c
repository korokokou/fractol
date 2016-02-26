/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:34:33 by takiapo           #+#    #+#             */
/*   Updated: 2015/04/30 02:28:18 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_img		*new_image(void *mlx)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
		&(img->size_line), &(img->endian));
	img->mlx = mlx;
	return (img);
}

void		reset_image(t_img *img)
{
	int		limit;
	int		start;

	start = 0;
	limit = SCREEN_W * SCREEN_H * 4;
	while (start < limit)
	{
		img->data[start] = 0;
		start++;
	}
}

void		add_point(t_img *img, int x, int y, int color_calc)
{
	int	color;

	color = mlx_get_color_value(img->mlx, color_calc);	
	if (img->endian == 0)
	{
		img->data[y * img->size_line + x * 4 + 3] = (color & 0xFF000000) >> 24;
		img->data[y * img->size_line + x * 4 + 2] = (color & 0xFF0000) >> 16;
		img->data[y * img->size_line + x * 4 + 1] = (color & 0xFF00) >> 8;
		img->data[y * img->size_line + x * 4 + 0] = (color & 0xFF);
	}
	else if (img->endian == 1)
	{
		img->data[y * img->size_line + x * 4 + 0] = (color & 0xFF000000) >> 24;
		img->data[y * img->size_line + x * 4 + 1] = (color & 0xFF0000) >> 16;
		img->data[y * img->size_line + x * 4 + 2] = (color & 0xFF00) >> 8;
		img->data[y * img->size_line + x * 4 + 3] = (color & 0xFF);
	}
}
