/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:59:44 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/19 16:20:28 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/*
void		sub_triangle(int n, t_coord first, t_coord second, t_coord third)
{
		
}
*/

void		draw_sierspinki(t_env *e)
{
	t_line	left;
	t_line	right;
	t_line	bottom;

	left.c1.x = SCREEN_W / 2;
	left.c1.y = 0;
	left.c2.x = 0;
	left.c2.y = SCREEN_H - 1;
	right.c1.x = SCREEN_W - 1;
	right.c1.y = SCREEN_H - 1;
	right.c2.x = SCREEN_W / 2;
	right.c2.y = 0;
	bottom.c1.x = 0;
	bottom.c1.y = SCREEN_H - 1;
	bottom.c2.x = SCREEN_W - 1;
	bottom.c2.y = SCREEN_H - 1;
	e->img = new_image(e->mlx, SCREEN_W, SCREEN_H);	
	draw_line_int(left, 0xFFFFBB, e->img);
	draw_line_int(right, 0xFFFFBB, e->img);
	draw_line_int(bottom, 0xFFFFBB, e->img);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
}

int			sierspinki_key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		e->motion ^= 1;
	return (0);
}

void		init_sierpinski(t_env *e)
{
	draw_sierspinki(e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, sierspinki_key_hook, e);
}
