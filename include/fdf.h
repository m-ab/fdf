/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:41:45 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 18:18:45 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 2000
# define HEIGHT 1200
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "mlx.h"
# include <libft.h>

typedef struct		s_img
{
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**tab;
	int				x;
	int				y;
	float			x0;
	float			y0;
	float			x1;
	float			y1;
	float			x_offset;
	float			y_offset;
	float			alt;
	float			zoom;
	int				xmax;
	int				ymax;
	t_img			img;
}					t_env;

int					get_next_line(int fd, char **line);
int					read_file(int fd, char *av);
void				get_tab(int **tab, int xmax, int ymax);
t_env				init_env(int **tab, int xmax, int ymax);
void				init_img(t_env *e);
int 				display_win(t_env *e);
void				display_menu(t_env *e);
void				draw(t_env *e);
void				color_alt_r(t_env *e, int pos);
void				color_alt_d(t_env *e, int pos);

#endif
