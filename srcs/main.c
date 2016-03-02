/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:37:58 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/02 13:51:52 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#define	MAXITERATION 128

void	julia(t_env *e, t_coord pixel, void *data)
{

	img = new_image(e->mlx, SCREEN_W, SCREEN_H);
	c.re = -0.2;
	c.im = 0.175;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			new.re = 1.5 * (x - SCREEN_W / 2) / ( 0.5 * SCREEN_W);
			new.im = (y - SCREEN_H / 2) / (0.5 * SCREEN_H);	
			i = 0;
			while (i < MAXITERATION)
			{
				old.re = new.re;
				new.re = old.re * old.re - old.im * old.im + c.re;
				new.im = 2 * old.re * new.im + c.im;
				if ((new.re * new.re + new.im * new.im) > 4)
					break ;
				i++;
			}
			color = (0x72A0C1 * i);
			add_point_int(img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, img->img_ptr, 0, 0);
}

int		main()
{
    t_env   e;

	e.mlx = mlx_init();
    if (e.mlx)
        e.win = mlx_new_window(e.mlx, SCREEN_W, SCREEN_H, "fractol");
	if (e.win)
	{
		julia(&e);
		mlx_loop(e.mlx); 
	}
	return (0);
}
