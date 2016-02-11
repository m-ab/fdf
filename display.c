/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:02:03 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 17:53:06 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	display_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	
	// ICI ON METTRA LE MENU ET LES OPTIONS

	// display_menu(e);
	// display_param(e);
	return (0);
}

int 	key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	else
		key_event(e, keycode);
	return (0);
}

void	get_tab(int **tab, int xmax, int ymax)
{
	t_env e;

	e = init_env(tab, xmax, ymax);
	draw(&e);
	mlx_key_hook(e.win, key_hook, &e);
	display_win(&e);
	mlx_loop(e.mlx);
}