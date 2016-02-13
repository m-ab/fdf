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

static int	draw_pixel_r(t_env *e, int x, int y)
{
	int pos;

	pos = (x * e->img.bpp / 8) + (y * e->img.sl);
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (e->tab[e->y][e->x] != 0 || (e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0)
			|| (e->tab[e->y][e->x] == 0 && e->tab[e->y][e->x + 1] != 0))
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

static int	draw_pixel_d(t_env *e, int x, int y)
{
	int pos;

	pos = (x * e->img.bpp / 8) + (y * e->img.sl);
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (e->tab[e->y][e->x] != 0 || (e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0)
			|| (e->tab[e->y][e->x] == 0 && e->tab[e->y + 1][e->x] != 0))
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

void		draw_line(t_env *e)
{
	int dist_x;
	int dist_y;
	int cursor;
	int max;

	e->x0 = (e->x - e->y) * e->zoom;
	e->y0 = (e->x + e->y) * (e->zoom / 2) - e->tab[e->y][e->x] * e->alt;
	e->x1 = ((e->x + 1) - e->y) * e->zoom;
	e->y1 = ((e->x + 1) + e->y) * (e->zoom / 2) - e->tab[e->y][e->x + 1] * e->alt;
	dist_x = e->x1 - e->x0;
	dist_y = e->y1 - e->y0;
	max = abs(dist_x) > abs(dist_y) ? abs(dist_x) : abs(dist_y);
	cursor = 0;
	while (cursor < max)
	{
		draw_pixel_r(e, e->x_offset + e->x0 + (cursor * dist_x) / max,
		e->y_offset + e->y0 + (cursor * dist_y) / max);
		cursor++;
	}
}

void		draw_col(t_env *e)
{
	int dist_x;
	int dist_y;
	int cursor;
	int max;

	e->x0 = (e->x - e->y) * e->zoom;
	e->y0 = (e->x + e->y) * (e->zoom / 2) - e->tab[e->y][e->x] * e->alt;
	e->x1 = (e->x - (e->y + 1)) * e->zoom;
	e->y1 = (e->x + (e->y + 1)) * (e->zoom / 2) - e->tab[e->y + 1][e->x] * e->alt;
	dist_x = e->x1 - e->x0;
	dist_y = e->y1 - e->y0;
	max = abs(dist_x) > abs(dist_y) ? abs(dist_x) : abs(dist_y);
	cursor = 0;
	while (cursor < max)
	{
		draw_pixel_d(e, e->x_offset + e->x0 + (cursor * dist_x) / max,
		e->y_offset + e->y0 + (cursor * dist_y) / max);
		cursor++;
	}
}

void		draw(t_env *e)
{
	e->y = 0;
	while (e->y < e->ymax)
	{
		e->x = 0;
		while (e->x < e->xmax)
		{
			if (e->x + 1 < e->xmax)
				draw_line(e);
			if (e->y + 1 < e->ymax)
		 		draw_col(e);
			e->x++;
		}
		e->y++;
	}
}
