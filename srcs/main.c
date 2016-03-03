/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:37:58 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/03 08:09:15 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#define	MAXITERATION 128

void    init_julia(void *data)
{
    data = malloc(sizeof(t_julia));
    if (!data)
        exit(-1);
}

int 	julia(t_coord pixel, void *data)
{

    int     i;
    t_julia *j;
    int     color;

    if (!data)
        exit (-1);
    i= 0;
    j = data;
    j->c.re = -0.2;
    j->c.im = 0.175;
    j->new.re = 1.5 * (pixel.x - SCREEN_W / 2) / ( 0.5 * SCREEN_W);
    j->new.im = (pixel.y - SCREEN_H / 2) / (0.5 * SCREEN_H);	
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
    void    *data;

    data = NULL;
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, SCREEN_W, SCREEN_H, "fractol");
    if (e.win)
    {
        e.fractal[0] = julia;
        e.init_data[0] = init_julia;
        init_julia(data);
        draw_fractal(&e, data);
          mlx_loop(e.mlx); 
    }
    return (0);
}
