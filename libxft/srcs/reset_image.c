/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:25:28 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 11:30:25 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibxft.h"

void		reset_image(t_img *img, int screen_width, int screen_height)
{
	int		limit;
	int		start;

	start = 0;
	limit = screen_width * screen_height * 4;
	while (start < limit)
	{
		img->data[start] = 0;
		start++;
	}
}
