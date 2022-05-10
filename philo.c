/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:02:14 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 16:45:06 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_fork	*forks;

	forks = NULL;
	if (argc == 5 || argc == 6)
	{
		if (ft_checking(argc, argv) == -1)
		{
			return (-1);
		}
		if (ft_init(argc, argv, forks) == -1)
		{
			return (-1);
		}
	}
	else
	{
		write(2, "\033[0;31m", 8);
		write(2, "Write Valid arguments", 22);
		return (1);
	}
}
