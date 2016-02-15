/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:16:23 by maboukra          #+#    #+#             */
/*   Updated: 2015/11/24 18:17:56 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar(s[count]);
		count++;
	}
	ft_putchar('\n');
}
