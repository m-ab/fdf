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

# define WIDTH 1200
# define HEIGHT 900
# define SIZE 20
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

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
	int 			x_offset;
	int				y_offset;
	int 			x_origin;
	int 			y_origin;
	int				xmax;
	int				ymax;
	t_img			img;
}					t_env;

int					get_next_line(int fd, char **line);
int					read_file(int fd, char *av);
void				get_tab(int **tab, int xmax, int ymax);
t_env				init_env(int **tab, int xmax, int ymax);
int					key_event(t_env *e, int keycode);
void				draw(t_env *e);

#endif
