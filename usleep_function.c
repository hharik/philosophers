/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:52:28 by hharik            #+#    #+#             */
/*   Updated: 2022/02/28 16:57:50 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	usleep_function(long sleep_time)
{
	struct timeval	before;
	struct timeval	now;

	gettimeofday(&before, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		if (((now.tv_sec - before.tv_sec) * 1e6) + \
		(now.tv_usec - before.tv_usec) >= sleep_time)
		{
			break ;
		}
		usleep(400);
	}
}
