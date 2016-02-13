/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 12:07:23 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 17:40:11 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_img(t_env *e)
{
	e->img.img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp,
	&e->img.sl, &e->img.endian);
}

void		init_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FDF");
	e->img.img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp,
	&e->img.sl, &e->img.endian);
}

t_env		init_env(int **tab, int xmax, int ymax)
{
	t_env e;
	e.x_offset = 500;
	e.y_offset = 250;
	// e.scale = ((double)(WIDTH + HEIGHT) / 2.0) /
	// ((double)(e.xmax + e.ymax) / 2.0);
	e.zoom = 20;
	e.alt = 0;
	e.tab = tab;
	e.xmax = xmax;
	e.ymax = ymax;
	init_win(&e);
	return (e);
}