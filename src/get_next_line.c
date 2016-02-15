/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:40:34 by maboukra          #+#    #+#             */
/*   Updated: 2016/01/09 16:40:37 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

static int		ft_cut_line(char *str_chr, char *save)
{
	save[0] = 0;
	if (!str_chr)
		return (0);
	*str_chr = '\0';
	str_chr++;
	ft_strcpy(save, str_chr);
	ft_bzero(str_chr, ft_strlen(str_chr));
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			*str_chr;
	char			buf[BUFF_SIZE + 1];
	static char		save[256][BUFF_SIZE];

	if (!line || fd < 0 || fd > 255 || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = *save[fd] ? ft_strdup(save[fd]) : ft_strnew(0)))
		return (-1);
	buf[0] = 0;
	while (!(str_chr = ft_strchr(*line, '\n')) &&
		(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*line = ft_strjoinf(*line, buf)))
			return (-1);
	}
	if (ft_cut_line(str_chr, save[fd]) || ft_strlen(*line) || ret > 0)
		return (1);
	return (ret == 0 ? 0 : -1);
}
