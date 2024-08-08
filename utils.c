/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:05:30 by rkrechun          #+#    #+#             */
/*   Updated: 2024/08/08 15:28:41 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	current_time(void)
{
	uint64_t		seconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	seconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (seconds);
}

void	ft_usleep(long int time)
{
	long int	start;

	start = current_time();
	while ((current_time() - start) < (unsigned long int) time)
		usleep(150);
}

void	print(t_philo *p, int i)
{
	pthread_mutex_lock(p->param->print);
	if (p->param->over)
	{
		pthread_mutex_unlock(p->param->print);
		return ;
	}
	if (i == 1)
		printf("%ld %d %s\n", current_time() - p->start, p->id,
			"has taken left fork");
	else if (i == 2)
		printf("%ld %d %s\n", current_time() - p->start, p->id,
			"is eating");
	else if (i == 3)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "is sleeping");
	else if (i == 4)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "is thinking");
	else if (i == 5)
		printf("%ld %d %s\n", current_time() - p->start, p->id, "died");
	else if (i == 6)
		printf("%ld %d %s\n", current_time() - p->start, p->id,
			"has taken right fork");
	pthread_mutex_unlock(p->param->print);
}

void	free_all(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->param->philo_nbr)
	{
		pthread_mutex_destroy(philo[i].forkl);
		pthread_mutex_destroy(philo[i].forkr);
	}
	pthread_mutex_destroy(philo->param->print);
	free(philo->param->forks);
	free(philo->param);
	free(philo);
}

void	error_print(void)
{
	printf("wrong number of arguments\n");
	printf("Follow the format below:\n");
	printf("./philo number_of_philosophers ");
	printf("time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}
