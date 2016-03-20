/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:22:40 by takiapo           #+#    #+#             */
/*   Updated: 2016/03/19 16:00:19 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibxft.h"

void		drawing_loop(t_line *line, int color, t_img *img, int *err)
{
	t_coord	diff;
	t_coord	step;
	int		e2;

	diff.x = ABS(line->c2.x - line->c1.x);
	diff.y = ABS(line->c2.y - line->c1.y);
	step.x = (line->c1.x < line->c2.x) ? 1 : -1;
	step.y = (line->c1.y < line->c2.y) ? 1 : -1;
	*err = (diff.x > diff.y ? diff.x : -diff.y) / 2;
	while (42)
	{
		add_point_int(img, line->c1.x, line->c1.y, color);
		e2 = *err;
		if (e2 >= -diff.x)
		{
			*err -= diff.y;
			line->c1.x += step.x;
		}
		if (e2 < diff.y)
		{
			*err += diff.x;
			line->c1.y += step.y;
		}
		if (line->c1.x == line->c2.x && line->c1.y == line->c2.y)
			break;
	}
}

int			draw_line_int(t_line line, int color, t_img *img)
{
	t_line	*line_drawn;
	int		err;

	line_drawn = malloc(sizeof(t_line));
	line_drawn->c1.x = line.c1.x;
	line_drawn->c1.y = line.c1.y;
	line_drawn->c2.x = line.c2.x;
	line_drawn->c2.y = line.c2.y;
	drawing_loop(line_drawn, color, img, &err);
	free(line_drawn);
	return (0);
}
