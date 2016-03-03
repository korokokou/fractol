/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:52:09 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 11:53:40 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibxft.h"

t_color		*itoc(int color_in_hex)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->red = (color_in_hex & 0xFF000000) >> 24;
	color->green = (color_in_hex & 0xFF0000) >> 16;
	color->blue = (color_in_hex & 0xFF00) >> 8;
	color->trans = (color_in_hex & 0xFF);
	return (color);
}
