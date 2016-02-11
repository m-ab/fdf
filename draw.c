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
		if (e->tab[y / SIZE][x / SIZE] != 0)
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

void	draw_line(int x0, int y0, int x1, int y1, t_env *e)
{
	int dist_x;
	int dist_y;
	int cursor;
	int max;

	dist_x = x1 - x0;
	dist_y = y1 - y0;
	max = abs(dist_x) > abs(dist_y) ? abs(dist_x) : abs(dist_y);
	cursor = -1;
	while (++cursor < max)
	{
		draw_pixel(e->x_origin + x0 + (cursor * dist_x) / max,
		e->y_origin + y0 + (cursor * dist_y) / max, e);
	}
}

void		draw(t_env *e)
{
	int 	x;
	int 	y;

	y = -1;

	while (++y < e->ymax)
	{
		x = -1;
		while (++x < e->xmax)
		{
			if (x + 1 < e->xmax)
		 		draw_line(x * SIZE, y * SIZE, (x + 1) * SIZE, y * SIZE, e);
		 	if (y + 1 < e->ymax)
		 		draw_line(x * SIZE, y * SIZE, x * SIZE, (y + 1) * SIZE, e);
		}
	}
}