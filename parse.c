/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:02:49 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/11 17:49:54 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*fill_tab(char *line, int *tab, int *xmax)
{
	int			x;
	char		**split;

	x = 0;
	split = ft_strsplit(line, ' ');
	tab = (int *)malloc(sizeof(int) * *xmax);
	while (split[x])
	{
		tab[x] = ft_atoi(split[x]);
		free(split[x]);
		x++;
	}
	free(split);
	return (tab);
}

static int		count_x(char const *line)
{
	int		index;
	int		x;

	index = 0;
	x = 0;
	while (line[index])
	{
		if (line[index] != ' ')
		{
			while (line[index] != ' ' && line[index])
				index++;
			x++;
		}
		else
			index++;
	}
	return (x);
}

static int		first_read(int fd, char *line, int *xmax, int *ymax)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (*xmax < count_x(line))
			*xmax = count_x(line);
		*ymax += 1;
		free(line);
	}
	close(fd);
	return (0);
}

int				read_file(int fd, char *av)
{
	int		xmax;
	int		ymax;
	int		y;
	int		**tab;

	xmax = 0;
	ymax = 0;
	y = 0;
	first_read(fd, av, &xmax, &ymax);
	if (!(tab = (int **)malloc(sizeof(int *) * ymax)))
		return (-1);
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &av) > 0)
	{
		tab[y] = fill_tab(av, tab[y], &xmax);
		y++;
		free(av);
	}
	close(fd);
	get_tab(tab, xmax, ymax);
	return (0);
}
