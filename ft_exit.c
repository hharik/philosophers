/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:11:18 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 16:05:22 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit(t_fork *forks, int number_philo)
{
	int		i;

	i = -1;
	while (++i < number_philo)
	{
		if (pthread_mutex_destroy(&forks->fork[i]) != 0)
			return (1);
	}
	if (pthread_mutex_destroy(&forks->philo->meal_check) != 0)
		return (1);
	if (pthread_mutex_destroy(&forks->philo->msg) != 0)
		return (1);
	return (0);
}
