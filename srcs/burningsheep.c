/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningsheep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:20:48 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/20 13:25:02 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	reiterate(t_complex new, t_complex old, t_complex c)
{
	int		i;
	int		color;
	t_complex	res;

	i= 0;
	while (i < MAXITERATION)
	{
		res.re = new.re * new.re;
		res.im = new.im * new.im;
		if (res.re + res.im > 4)
			break ;
		old.re = new.re;
		new.re = res.re - res.im + c.re;
		new.im = fabs(2 * old.re * new.im) + c.im;
		i++;
	}
	color = (0x72A0C1 * i);
	return (color);
}

void		draw_burningsheep(t_env *e, void *data)
{
	t_coord pixel;
	int	color;
	t_burningsheep	*j;

	j = data;	
	e->img = new_image(e->mlx, SCREEN_W, SCREEN_H);
	color = 0;
	pixel.y = 0;
	j->c.im = -1 + j->move.y;
	delete_coords(&(j->old), &(j->new));
	while (pixel.y < SCREEN_H)
	{
		pixel.x = 0;
		j->c.re = -3.5 + j->move.x;
		while (pixel.x < SCREEN_W)
		{
			color = reiterate(j->new, j->old, j->c);
			add_point_int(e->img, pixel.x, pixel.y, color);
			pixel.x++;
			j->c.re += j->step.re;
		}
		pixel.y++;
		j->c.im += j->step.im;	
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
}

int			burningsheep_key_hook(int keycode, t_env *e)
{
	t_burningsheep *j;

	j = e->data;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		init_burningsheep(t_env *e)
{
	t_burningsheep *j;	
	e->data = malloc(sizeof(t_burningsheep));
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
	draw_burningsheep(e, e->data);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, burningsheep_key_hook, e);
}
