/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:46:14 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 11:56:23 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibxft.h"

int			ctoi(t_color color)
{
	int		int_in_hex;

	int_in_hex = 0; 
	int_in_hex |= (color.red << 24);
	int_in_hex |= (color.green << 16);
	int_in_hex |= (color.blue << 8);
	int_in_hex |= (color.trans);
	return (int_in_hex);
}
