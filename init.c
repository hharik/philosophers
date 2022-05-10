/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:59:29 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 17:02:09 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_alloc(t_fork	**forks, int number_philo)
{
	*forks = malloc(sizeof(t_fork));
	if (!(*forks))
		return (0);
	(*forks)->philo = malloc(sizeof(t_philo) * number_philo);
	if (!(*forks)->philo)
		return (0);
	(*forks)->fork = malloc(sizeof(pthread_mutex_t) * (number_philo));
	if (!(*forks)->fork)
		return (0);
	return (1);
}

int	ft_init(int argc, char **argv, t_fork *forks)
{
	int	i;
	int	number_philo;

	number_philo = ft_atoi(argv[1]);
	ft_alloc(&forks, number_philo);
	forks->philo->dead = 0;
	forks->philo->x_ate = 0;
	forks->philo->total_philo = ft_atoi(argv[1]);
	i = -1;
	if (pthread_mutex_init(&forks->philo->meal_check, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&forks->philo->msg, NULL) != 0)
		return (-1);
	while (++i < number_philo)
		if (pthread_mutex_init(&forks->fork[i], NULL) != 0)
			return (-1);
	if (create_thread(forks, argv, argc) == -1)
		return (-1);
	if (check_is_dead(forks->philo) == 0)
		return (-1);
	if (ft_exit(forks, forks->philo->total_philo) == 1)
		return (-1);
	return (1);
	usleep(100);
}
