/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:26:25 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 16:05:43 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct philosophers
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	msg;
	pthread_mutex_t	meal_check;
	pthread_t		philosopher;
	int				dead;
	int				total_philo;
	long long		sleep_time;
	long long		time_to_eat;
	long long		time_to_die;
	int				number_philo;
	long			each_time_eat;
	int				philo_i;
	long			last_meal;
	int				x_ate;
	long long		num;
}	t_philo;

typedef struct forks
{
	pthread_mutex_t	*fork;
	t_philo			*philo;
	int				number_forks;
}	t_fork;

int			check_is_dead(t_philo *phil);
long long	ft_atoi(const char *nptr);
int			ft_init(int argc, char **argv, t_fork *forks);
int			ft_exit(t_fork *fork, int number_philo);
int			ft_checking(int argc, char **argv);
void		usleep_function(long sleep_time);
int			create_thread(t_fork *forks, char **argv, int argc);
long		timestamp(void);

#endif