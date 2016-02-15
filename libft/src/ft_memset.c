/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:55:51 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:44:52 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*result;

	count = 0;
	result = (char*)b;
	while (count < len)
	{
		result[count] = (unsigned char)c;
		count++;
	}
	return ((void*)result);
}
