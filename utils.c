/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:05:30 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/25 17:21:31 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

uint64_t current_time(void)
{
	uint64_t seconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	seconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return(seconds);
}

void ft_usleep(uint64_t time)
{
	uint64_t start;

	start = current_time();
	while (current_time() - start < time)
		usleep(100);
}

void print(t_philo *p, int i)
{
	pthread_mutex_lock(p->param->print);
	if(p->over)
	{
		pthread_mutex_unlock(p->param->print);
		return ;
	}
	if (i == i)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "has taken a fork");
	else if (i == 2)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "is eating");
	else if (i == 3)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "is sleeping");
	else if (i == 4)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "is thinking");
	else if (i == 5)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "died");
	else if (i == 6)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "has taken a fork");
	pthread_mutex_unlock(p->param->print);
}