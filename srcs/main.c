/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:37:58 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/03 16:18:32 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#define	MAXITERATION 256

void    	draw_fractal(t_env *e, void *data);

int			enter_window_hook(int x, int y, t_env *e)
{
	t_julia *j;

	j = e->data;
	e->old_pos.x = x;
	e->old_pos.y = y;
	return (0);
}

int			abs(int x)
{
	int	result;
	int	mask;

	mask = x >> (sizeof(int) * CHAR_BIT - 1);
	result = (x + mask) ^ x;
	return (result);
}

int			mouse_hook(int x, int y, t_env *e)
{
	t_julia *j;

	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H)
	{
		j = e->data;
		j->c.im += (e->old_pos.x - x) * 0.003;
		j->c.re += (e->old_pos.y - y) * 0.003;
       	e->old_pos.x = x;
		e->old_pos.y = y;
		draw_fractal(e, e->data);
	}	
	return (0);
}

int			expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 53)
		exit(0);
	return (0);
}

void    init_julia(void **data)
{
    t_julia *j;	
	*data = malloc(sizeof(t_julia));
    if (!*data)
        exit(-1);
	j = *data;
	j->c.re = -0.2;
	j->c.im = 0.175;
	j->step.re = (3.0f / SCREEN_W);
    j->step.im = (2.0f / SCREEN_H);	
	j->new.re = -1.5;
    j->new.im = -1;	
	printf("%f   %f\n", j->step.re, j->step.im);
}

int 	julia(t_coord pixel, void *data)
{
    int     i;
    t_julia *j;
    int     color;

    i= 0;
	j = data;
//	j->new.re += j->step.re;
 //   j->new.im += j->step.im;	
	j->new.re = 1.5 * pixel.x / (0.5 * SCREEN_W) - 1.5;
    j->new.im = pixel.y / (0.5 * SCREEN_H) - 1;	
	printf("%f   %f\n", j->new.re - (1.5 *( pixel.x - 1) / (0.5 * SCREEN_W) - 1.5), j->new.im  * ((pixel.y  -1)/ (0.5 * SCREEN_H) - 1));
	(void)pixel;
	while (i < MAXITERATION)
    {
        j->old.re = j->new.re;
        j->new.re = j->old.re * j->old.re - j->old.im * j->old.im
            + j->c.re;
        j->new.im = 2 * j->old.re * j->new.im + j->c.im;
        if ((j->new.re * j->new.re + j->new.im * j->new.im) > 4)
            break ;
        i++;
    }
    color = (0x72A0C1 * i);
    return (color);
}

void    draw_fractal(t_env *e, void *data)
{
    t_coord pixel;
    int     color;
    
    e->img = new_image(e->mlx, SCREEN_W, SCREEN_H);
    color = 0;
    pixel.y = 0;
    while (pixel.y < SCREEN_H)
    {
        pixel.x = 0;
        while (pixel.x < SCREEN_W)
        {
            color = e->fractal[0](pixel, data);
            add_point_int(e->img, pixel.x, pixel.y, color);
            pixel.x++;
        }
        pixel.y++;
    }
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
}

int		main(void)
{
    t_env   e;

    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, SCREEN_W, SCREEN_H, "fractol");
	if (e.win)
    {
        e.fractal[0] = julia;
        e.init_data[0] = init_julia;
        init_julia(&(e.data));
        draw_fractal(&e, e.data);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, key_hook, &e);
		mlx_hook(e.win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_hook, &e);
		mlx_hook(e.win, ENTERNOTIFY, ENTERWINDOWMASK, enter_window_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx); 
    }
    return (0);
}
