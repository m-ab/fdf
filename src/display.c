/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:02:03 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/15 16:56:55 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF,
		"Use arrow keys to move object");
	mlx_string_put(e->mlx, e->win, 20, 34, 0xFFFFFF,
		"+/- on the numeric keypad to increase or decrease zoom");
	mlx_string_put(e->mlx, e->win, 20,
		HEIGHT - 42, 0xFFFFFF, "Zoom level:");
	mlx_string_put(e->mlx, e->win, 20, 48, 0xFFFFFF,
		"9/6 to increase or decrease relief");
	mlx_string_put(e->mlx, e->win, 133,
		HEIGHT - 42, 0xFFFFFF, ft_itoa(e->zoom / 5));
	mlx_string_put(e->mlx, e->win, 20,
		HEIGHT - 70, 0xFFFFFF, "Relief level:");
	mlx_string_put(e->mlx, e->win, 152,
		HEIGHT - 70, 0xFFFFFF, ft_itoa(e->alt));
}

int		display_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	display_menu(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123)
		e->x_offset -= 50;
	if (keycode == 124)
		e->x_offset += 50;
	if (keycode == 125)
		e->y_offset += 50;
	if (keycode == 126)
		e->y_offset -= 50;
	if (keycode == 69)
		e->zoom += 0.5;
	if (keycode == 78 && e->zoom > 5)
		e->zoom -= 0.5;
	if (keycode == 88)
		e->alt += 0.5;
	if (keycode == 92)
		e->alt -= 0.5;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img_ptr);
	init_img(e);
	draw(e);
	display_win(e);
	return (0);
}

void	get_tab(int **tab, int xmax, int ymax)
{
	t_env e;

	e = init_env(tab, xmax, ymax);
	draw(&e);
	mlx_hook(e.win, 2, 1, key_hook, &e);
	display_win(&e);
	mlx_loop(e.mlx);
}
