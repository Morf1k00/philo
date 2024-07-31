/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:02 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/31 13:38:22 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	print(p, 1);
	pthread_mutex_lock(p->forkr);
	print(p, 6);
	p->meal = current_time();
	p->iter++;
	print(p, 2);
	ft_usleep(p->param->eat_time);
	pthread_mutex_unlock(p->forkl);
	pthread_mutex_unlock(p->forkr);
}

void	*routine(void *phil)
{
	t_philo	*p;

	p = (t_philo *)phil;
	while (!(p->param->ready))
		continue ;
	if (p->id % 2)
		ft_usleep(p->param->eat_time * 0.9 + 1);
	while (!(p->param->over))
	{
		ft_eat(p);
		pthread_mutex_lock(p->param->print);
		if (p->param->check_sum && p->iter == p->param->eat_count)
		{
			p->param->eated++;
			pthread_mutex_unlock(p->param->print);
			return (NULL);
		}
		pthread_mutex_unlock(p->param->print);
		print(p, 3);
		ft_usleep(p->param->sleep_time);
		print(p, 4);
	}
	return (NULL);
}
