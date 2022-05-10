/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:43:02 by hharik            #+#    #+#             */
/*   Updated: 2022/02/26 14:55:40 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	return (1);
}

static long long	ft_range(const char *chr)
{
	int			index;
	long long	ret;

	ret = 0;
	index = 0;
	while (ft_isdigit(chr[index]))
	{
		ret = (ret * 10) + (chr[index] - '0');
		index++;
		if ((ret > 9223372036854775807))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (ret);
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	result = ft_range(&nptr[i]);
	return (result * sign);
}
