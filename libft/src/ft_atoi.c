/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:00:07 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/15 17:49:18 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_solve(const char *str, int count, int result, int sign)
{
	while (ft_isdigit(str[count]) == 1)
	{
		if (str[count] >= '0' && str[count] <= '9')
			result = result * 10 + (str[count] - '0');
		else if (str[count++] == ' ')
			return (result * sign);
		count++;
	}
	return (result);
}

int			ft_atoi(const char *str)
{
	int	result;
	int	count;
	int	sign;

	sign = 1;
	count = 0;
	result = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\t' ||
			str[count] == '\v' || str[count] == '\f' || str[count] == '\r')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	result = ft_solve(str, count, result, sign);
	return (result * sign);
}
