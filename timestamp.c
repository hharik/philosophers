/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharik <hharik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:47:51 by hharik            #+#    #+#             */
/*   Updated: 2022/02/25 18:05:32 by hharik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	timestamp(void)
{
	struct timeval	te;
	long long		mili;

	gettimeofday(&te, NULL);
	mili = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (mili);
}
