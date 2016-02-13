/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:13:19 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 16:39:00 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_event(t_env *e, int keycode)
{
	if (keycode == 123)
		e->x_offset -= 50;
	if (keycode == 124)
		e->x_offset += 50;
	if (keycode == 125)
		e->y_offset += 50;
	if (keycode == 126)
		e->y_offset -= 50;
	if (keycode == 69)
		e->zoom += 5;
	if (keycode == 78 && e->zoom > 5)
		e->zoom -= 5;
	if (keycode == 85)
		e->alt += 1;
	if (keycode == 86)
		e->alt -= 1;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img_ptr);
	init_img(e);
	draw(e);
	display_win(e);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}