/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:52:56 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:45:35 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	count_size;

	count_size = 0;
	while (src[count_size] != '\0')
	{
		dst[count_size] = src[count_size];
		count_size++;
	}
	dst[count_size] = '\0';
	return (dst);
}
