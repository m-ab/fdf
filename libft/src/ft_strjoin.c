/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:44:24 by maboukra          #+#    #+#             */
/*   Updated: 2016/01/08 14:11:00 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	int		count1;
	int		count2;
	char	*buf;

	count1 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(buf = ft_strnew(len)))
		return (NULL);
	while (s1[count1])
	{
		buf[count1] = s1[count1];
		count1++;
	}
	count2 = 0;
	while (s2[count2])
		buf[count1++] = s2[count2++];
	buf[count1] = '\0';
	return (buf);
}
