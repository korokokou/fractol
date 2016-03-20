/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:26:33 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/20 13:29:26 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_julia(t_env *e, void *data)
{
	t_coord pixel;
	int	color;
	t_julia	*j;

	j = data;	
	e->img = new_image(e->mlx, SCREEN_W, SCREEN_H);
	color = 0;
	pixel.y = 0;
	j->new.im = -1 + j->move.y;
	while (pixel.y < SCREEN_H)
	{
		pixel.x = 0;
		j->new.re = -1.5 + j->move.x;
		while (pixel.x < SCREEN_W)
		{
			color = iterate(j->new, j->old, j->c);
			add_point_int(e->img, pixel.x, pixel.y, color);
			pixel.x++;
			j->new.re += j->step.re;
		}
		pixel.y++;
		j->new.im += j->step.im;	
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
}

int			julia_zoom_hook(int button, int x, int y, t_env *e)
{
(void)x;
(void)y;
(void)e;
(void)button;

	/*
	t_julia *j;

	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H)
	{
		j = e->data;
		if (button == 4)
		{
			j->step.re /= 1.1;
			j->step.im /= 1.1;
			j->move.x += x * j->step.re;
			j->move.y += y * j->step.im;
			draw_julia(e, e->data);
		}
		if (button == 5)
		{
			j->step.re *= 1.1;
			j->step.im *= 1.1;
			j->move.x += x * j->step.re;
			j->move.y += y * j->step.im;
			draw_julia(e, e->data);
		}
	}
*/
	return (0);
}

int			julia_mouse_hook(int x, int y, t_env *e)
{
	t_julia *j;

	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H && e->motion == 0)
	{
		j = e->data;
		j->c.im += (e->old_pos.x - x) * 0.003;
		j->c.re += (e->old_pos.y - y) * 0.003;
		e->old_pos.x = x;
		e->old_pos.y = y;
		draw_julia(e, e->data);
	}	
	return (0);
}

int			julia_key_hook(int keycode, t_env *e)
{
	t_julia *j;

	j = e->data;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		e->motion ^= 1;
	return (0);
}

void		init_julia(t_env *e)
{
	t_julia *j;	
	e->data = malloc(sizeof(t_julia));
	if (!e->data)
		exit(-1);
	j = e->data;
	j->c.re = -0.2;
	j->c.im = 0.175;
	j->step.re = (3.0f / SCREEN_W);
	j->step.im = (2.0f / SCREEN_H);	
	j->new.re = -100;
	j->new.im = -100;	
	j->move.x = 0;
	j->move.y = 0;
	e->motion = 0;
	draw_julia(e, e->data);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, julia_key_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, julia_mouse_hook, e);
	mlx_mouse_hook(e->win, julia_zoom_hook, e);
}
