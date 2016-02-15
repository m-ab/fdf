/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:40:58 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 19:01:45 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_alt_z(t_env *e, int pos)
{
	if ((e->tab[e->y][e->x] != 0 ||
		(e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0) ||
		(e->tab[e->y][e->x] == 0 && e->tab[e->y][e->x + 1] != 0))
		&& e->alt == 0)
	{
		e->img.img[pos] = 150;
		e->img.img[pos + 1] = 150;
		e->img.img[pos + 2] = 150;
	}
	else
	{
		e->img.img[pos] = 255;
		e->img.img[pos + 1] = 255;
		e->img.img[pos + 2] = 255;
	}
}

void	color_alt_r(t_env *e, int pos)
{
	if ((e->tab[e->y][e->x] != 0 ||
		(e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0) ||
		(e->tab[e->y][e->x] == 0 && e->tab[e->y][e->x + 1] != 0))
		&& e->alt > 0)
	{
		e->img.img[pos] = 255;
		e->img.img[pos + 1] = 129;
		e->img.img[pos + 2] = 87;
	}
	else if ((e->tab[e->y][e->x] != 0 ||
		(e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0) ||
		(e->tab[e->y][e->x] == 0 && e->tab[e->y][e->x + 1] != 0))
		&& e->alt < 0)
	{
		e->img.img[pos] = 61;
		e->img.img[pos + 1] = 0;
		e->img.img[pos + 2] = 245;
	}
	else
		color_alt_z(e, pos);
}

void	color_alt_d(t_env *e, int pos)
{
	if ((e->tab[e->y][e->x] != 0 ||
		(e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0) ||
		(e->tab[e->y][e->x] == 0 && e->tab[e->y + 1][e->x] != 0))
		&& e->alt > 0)
	{
		e->img.img[pos] = 255;
		e->img.img[pos + 1] = 129;
		e->img.img[pos + 2] = 87;
	}
	else if ((e->tab[e->y][e->x] != 0 ||
			(e->tab[e->y][e->x + 1] == 0 && e->tab[e->y][e->x] != 0) ||
			(e->tab[e->y][e->x] == 0 && e->tab[e->y + 1][e->x] != 0))
			&& e->alt < 0)
	{
		e->img.img[pos] = 61;
		e->img.img[pos + 1] = 0;
		e->img.img[pos + 2] = 245;
	}
	else
		color_alt_z(e, pos);
}
