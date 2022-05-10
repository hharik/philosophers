/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:08:15 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 17:00:55 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_is_dead(t_philo *phil)
{
	int		i;

	while (!(phil->dead))
	{
		i = -1;
		while (++i < phil->total_philo && (phil->dead) == 0)
		{
			if ((timestamp() - phil->last_meal) >= phil->time_to_die)
			{
				pthread_mutex_lock(&phil->msg);
				printf("%lld %d died\n", \
				(timestamp() - phil->num), i + 1);
				phil->dead = 1;
				return (0);
			}
		}
		usleep(50);
		if (phil->each_time_eat != -1 && phil->x_ate > phil->each_time_eat)
		{
			phil->dead = 1;
			return (0);
		}
		usleep(100);
	}
	return (1);
}
