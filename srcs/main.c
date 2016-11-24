/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:10:20 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/20 15:43:27 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int			expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_ptr, 0, 0);
	return (0);
}

int 	iterate(t_complex new, t_complex old, t_complex c)
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
		new.im = 2 * old.re * new.im + c.im;
		i++;
	}
	color = (0x72A0C1 * i);
	return (color);
}

int		main(int ac, char **av)
{
	t_env   e;

	if (ac != 2)
		return (0);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, SCREEN_W, SCREEN_H, "fractol");
	if (!e.win)
		return (0);
	if (!ft_strcmp("julia", av[1]))
		init_julia(&e);
	else if (!ft_strcmp("mandelbrot", av[1]))
		init_mandelbrot(&e);
	else if (!ft_strcmp("sierpinski", av[1]))
		init_sierpinski(&e);
	else if (!ft_strcmp("burningsheep", av[1]))
		init_burningsheep(&e);
	else
	{
		ft_putendl("fractol: usage \"fractol [julia, mandelbrot, sierpinski]\""); 
		exit (-1);
	}
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, ENTERNOTIFY, ENTERWINDOWMASK, enter_window_hook, &e);
	mlx_loop(e.mlx); 
	return (0);
}
