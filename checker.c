/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:18:11 by rkrechun          #+#    #+#             */
/*   Updated: 2024/08/08 15:15:21 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *p)
{
	long int	time;

	pthread_mutex_lock(p->param->print);
	time = current_time() - p->meal;
	if (time >= p->param->time_to_die)
	{
		pthread_mutex_unlock(p->param->print);
		print(p, 5);
		pthread_mutex_unlock(p->forkl);
		pthread_mutex_unlock(p->forkr);
		return (1);
	}
	pthread_mutex_unlock(p->param->print);
	return (0);
}

void	check_threds(t_philo *p)
{
	int	i;

	while (!p->param->ready)
		usleep(100);
	while (!p->param->over)
	{
		i = -1;
		while (++i < p->param->philo_nbr)
		{
			if (check_death(&p[i]))
				p->param->over = 1;
		}
		if (p->param->eated == p->param->philo_nbr)
			p->param->over = 1;
	}
	usleep(100);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	arg_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!arg_nbr(argv[i]))
			return (0);
		i++;
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argv[5] && ft_atoi(argv[5]) <= 0))
		return (0);
	return (1);
}
