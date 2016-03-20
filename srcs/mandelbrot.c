/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:20:48 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/17 16:57:24 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_mandelbrot(t_env *e, void *data)
{
	t_coord pixel;
	int	color;
	t_mandelbrot	*j;

	j = data;	
	e->img = new_image(e->mlx, SCREEN_W, SCREEN_H);
	color = 0;
	pixel.y = 0;
	j->c.im = -1 + j->move.y;
	delete_coords(&(j->old), &(j->new));
	while (pixel.y < SCREEN_H)
	{
		pixel.x = 0;
		j->c.re = -1.5 + j->move.x;
		while (pixel.x < SCREEN_W)
		{
			color = iterate(j->new, j->old, j->c);
			add_point_int(e->img, pixel.x, pixel.y, color);
			pixel.x++;
			j->c.re += j->step.re;
		}
		pixel.y++;
		j->c.im += j->step.im;	
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
}

int			mandelbrot_zoom_hook(int button, int x, int y, t_env *e)
{
	t_mandelbrot *j;

	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H)
	{
		j = e->data;
		j->move.x += x / 1000;
		j->move.y += y / 1000;
		if (button == 5)
		{
			j->step.re /= 1.1;
			j->step.im /= 1.1;
			draw_mandelbrot(e, e->data);
		}
		if (button == 4)
		{
			j->step.re *= 1.1;
			j->step.im *= 1.1;
			draw_mandelbrot(e, e->data);
		}
	}
	return (0);
}

int			mandelbrot_mouse_hook(int x, int y, t_env *e)
{
	t_mandelbrot *j;

	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H)
	{
		j = e->data;
		j->c.im += (e->old_pos.x - x) * 0.003;
		j->c.re += (e->old_pos.y - y) * 0.003;
		e->old_pos.x = x;
		e->old_pos.y = y;
		draw_mandelbrot(e, e->data);
	}	
	return (0);
}

int			mandelbrot_key_hook(int keycode, t_env *e)
{
	t_mandelbrot *j;

	j = e->data;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		init_mandelbrot(t_env *e)
{
	t_mandelbrot *j;	
	e->data = malloc(sizeof(t_mandelbrot));
	if (!e->data)
		exit(-1);
	j = e->data;
	j->c.re = -7.5;
	j->c.im = -1;
	j->step.re = (3.0f / SCREEN_W);
	j->step.im = (2.0f / SCREEN_H);	
	j->new.re = -100;
	j->new.im = -100;	
	j->move.x = 0;
	j->move.y = 0;
	draw_mandelbrot(e, e->data);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, mandelbrot_key_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, mandelbrot_mouse_hook, e);
	mlx_mouse_hook(e->win, mandelbrot_zoom_hook, e);
}
