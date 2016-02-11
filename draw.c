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
	if (e->tab[y / SIZE][x / SIZE] != 0)
	{
		e->img.img[pos] = 255;
		e->img.img[pos + 1] = 255;
		e->img.img[pos + 2] = 255;	
	}
	else
	{
		e->img.img[pos] = 160;
		e->img.img[pos + 1] = 0;
		e->img.img[pos + 2] = 0;
	}
	return (0);
}

// static void draw_line(int x0, int y0, int x1, int y1, t_env *e)
// { 
//   int dx;
//   int sx;
//   int dy;
//   int sy;
//   int err;
//   int e2;

//   dx = abs(x1 - x0);
//   sx = x0 < x1 ? 1 : -1;
//   dy = abs(y1 - y0);
//   sy = y0 < y1 ? 1 : -1; 
//   err = (dx > dy ? dx : -dy) / 2;
//   while (1)
//   {
//     draw_pixel(x0, y0, e);
//     if (x0 == x1 && y0 == y1) 
//     	break;
//     e2 = err;
//     if (e2 >-dx) 
//     { 
//     	err -= dy;
//     	x0 += sx;
//     }
//     if (e2 < dy)
//     {
//     	err += dx;
//     	y0 += sy;
//     }
//   }
// }

void	draw_line(int x0, int y0, int x1, int y1, t_env *e)
{
	int d_x;
	int d_y;
	int c;
	int m;

	d_x = x1 - x0;
	d_y = y1 - y0;
	m = abs(d_x) > abs(d_y) ? abs(d_x) : abs(d_y);
	c = -1;
	while (++c < m)
	{
		draw_pixel(e->x_origin + x0 + (c * d_x) / m,
		e->y_origin + y0 + (c * d_y) / m, e);
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
// TEST
	// if (x + 1 < e->xmax)
	// 	draw_line(x + (x - y) * SIZE, 
	// 	y + (y + x) * (SIZE/2) - e->tab[y][x], 
	// 	x + ((x + 1) - y) * SIZE,
	// 	y + (y + (x + 1)) * (SIZE/2) - e->tab[y][x+1], 
	// 	e, x, y);
	// if (y + 1 < e->ymax)
	// 	draw_line(x + (x - y) * SIZE, 
	// 	y + (y + x) * (SIZE/2) - e->tab[y][x], 
	// 	x + (x - (y+1)) * SIZE,
	// 	y + ((y+1) + x) * (SIZE/2) - e->tab[y+1][x], 
	// 	e, x, y);
	// x++;