/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:33:47 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 17:00:52 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->msg);
	printf("%lld %d is thinking\n", ((timestamp() - philo->num)),
		philo->number_philo + 1);
	pthread_mutex_unlock(&philo->msg);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->msg);
	printf("%lld %d is sleeping \n",
		((timestamp() - philo->num)), philo->number_philo + 1);
	pthread_mutex_unlock(&philo->msg);
	usleep_function(philo->sleep_time * 1000);
}

void	eating(t_philo *m)
{
	pthread_mutex_lock(m->right);
	pthread_mutex_lock(&m->msg);
	printf("%lld %d has taken a fork\n",
		((timestamp() - m->num)), m->number_philo + 1);
	pthread_mutex_unlock(&m->msg);
	pthread_mutex_lock(m->left);
	pthread_mutex_lock(&m->msg);
	printf("%lld %d has taken a fork\n",
		((timestamp() - m->num)), m->number_philo + 1);
	pthread_mutex_unlock(&m->msg);
	pthread_mutex_lock(&m->msg);
	printf("%lld %d has started eating\n", ((timestamp() - m->num)),
		m->number_philo + 1);
	m->x_ate++;
	pthread_mutex_unlock(&m->msg);
	pthread_mutex_lock(&m->meal_check);
	m->last_meal = timestamp();
	usleep_function(m->time_to_eat * 1000);
	pthread_mutex_unlock(&m->meal_check);
	pthread_mutex_unlock(m->right);
	pthread_mutex_unlock(m->left);
}

void	*routine(void *mut)
{
	t_philo	*phil;
	int		i;

	i = -1;
	phil = (t_philo *)mut;
	phil->num = timestamp();
	while (1)
	{
		eating(phil);
		sleeping(phil);
		thinking(phil);
		usleep(100);
	}
	return (NULL);
}

int	create_thread(t_fork *forks, char **argv, int argc)
{
	int		i;

	i = 0;
	while (i < forks->philo->total_philo)
	{
		if (argc == 6)
			forks->philo[i].each_time_eat = ft_atoi(argv[5]);
		else
			forks->philo[i].each_time_eat = -1;
		forks->philo[i].total_philo = ft_atoi(argv[1]);
		forks->philo[i].time_to_die = ft_atoi(argv[2]);
		forks->philo[i].time_to_eat = ft_atoi(argv[3]);
		forks->philo[i].sleep_time = ft_atoi(argv[4]);
		forks->philo[i].right = &forks->fork[i];
		forks->philo[i].left = &forks->fork[(i + 1) \
		% forks->philo->total_philo];
		forks->philo[i].number_philo = i;
		if (pthread_create(&forks->philo[i].philosopher, \
		NULL, routine, &forks->philo[i]) != 0)
			return (-1);
		forks->philo[i].last_meal = timestamp();
		usleep(100);
		i++;
	}
	return (0);
}
