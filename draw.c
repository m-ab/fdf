/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:40:58 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 19:01:45 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static int	draw_pixel(int x, int y, t_env *e)
{
	int pos;

	pos = (x * e->img.bpp / 8) + (y * e->img.sl);
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (e->tab[(y - e->y_offset) / e->zoom]
			[(x - e->x_offset) / e->zoom] != 0)
		{
			e->img.img[pos] = 255;
			e->img.img[pos + 1] = 255;
			e->img.img[pos + 2] = 255;
		}
		else
		{
			e->img.img[pos] = 150;
			e->img.img[pos + 1] = 90;
			e->img.img[pos + 2] = 0;
		}
	}
	return (0);
}

void		draw_line(t_env *e, int x, int y)
{
	int dist_x;
	int dist_y;
	int cursor;
	int max;

	dist_x = x - e->x0;
	dist_y = y - e->y0;
	max = abs(dist_x) > abs(dist_y) ? abs(dist_x) : abs(dist_y);
	cursor = -1;
	while (++cursor < max)
	{
		draw_pixel(e->x_offset + e->x0 + (cursor * dist_x) / max,
		e->y_offset + e->y0 + (cursor * dist_y) / max, e);
	}
}

void		draw(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->ymax)
	{
		x = -1;
		while (++x < e->xmax)
		{
			e->x0 = x * e->zoom;
			e->y0 = y * e->zoom;
			if (x + 1 < e->xmax)
				draw_line(e, (x + 1) * e->zoom, y * e->zoom);
			if (y + 1 < e->ymax)
		 		draw_line(e, x * e->zoom, (y + 1) * e->zoom);
		}
	}
}
