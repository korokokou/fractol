/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_point_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:28:41 by takiapo           #+#    #+#             */
/*   Updated: 2017/12/19 16:10:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibxft.h"

void		add_point_int(t_img *img, int x, int y, int color_calc)
{
	int	color;
	t_color	*colorx;

	color = mlx_get_color_value(img->mlx, color_calc);	
	colorx = itoc(color);
	if (img->endian == 0)
	{
		img->data[y * img->size_line + x * 4 + 3] = colorx->red;
		img->data[y * img->size_line + x * 4 + 2] = colorx->green;
		img->data[y * img->size_line + x * 4 + 1] = colorx->blue;
		img->data[y * img->size_line + x * 4 + 0] = colorx->trans;
	}
	else if (img->endian == 1)
	{
		img->data[y * img->size_line + x * 4 + 0] = colorx->red;
		img->data[y * img->size_line + x * 4 + 1] = colorx->blue;
		img->data[y * img->size_line + x * 4 + 2] = colorx->green;
		img->data[y * img->size_line + x * 4 + 3] = colorx->trans;
	}
	free(colorx);
}
