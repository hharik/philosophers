/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:27:30 by hharik            #+#    #+#             */
/*   Updated: 2022/05/10 14:25:53 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isalpha(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= 'a' && argv[i] <= 'z') \
			|| (argv[i] >= 'A' && argv[i] <= 'Z'))
		{
			return (-1);
		}
	i++;
	}
	return (0);
}

int	ft_checking(int argc, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_isalpha(argv[i]) == -1)
			return (-1);
		i++;
	}
	if (argc == 5)
	{
		if ((ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0 || \
		ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0))
			return (-1);
	}
	if (argc == 6)
	{
		if ((ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0 || \
		ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0) || ft_atoi(argv[5]) <= 0)
			return (-1);
	}
	return (0);
}
