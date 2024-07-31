/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:26:31 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/31 13:37:27 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_param	*parse_line(char **argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (param == NULL)
		return (NULL);
	param->print = malloc(sizeof(pthread_mutex_t));
	if (param->print == NULL)
		return (NULL);
	param->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (param->forks == NULL)
		return (NULL);
	param->time_to_die = ft_atoi(argv[2]);
	param->eat_time = ft_atoi(argv[3]);
	param->check_sum = 0;
	param->sleep_time = ft_atoi(argv[4]);
	param->eated = 0;
	if (argv[5])
	{
		param->check_sum = 1;
		param->eat_count = ft_atoi(argv[5]);
	}
	param->philo_nbr = ft_atoi(argv[1]);
	param->ready = 0;
	param->over = 0;
	return (param);
}

void	join_threads(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->param->philo_nbr)
		pthread_join(philo[i].thread, (void *)&philo[i]);
}

void	create_threads(t_philo *philo)
{
	int			i;
	long int	time;

	i = -1;
	while (++i < philo->param->philo_nbr)
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
	i = -1;
	time = current_time();
	while (++i < philo->param->philo_nbr)
	{
		philo[i].start = time;
		philo[i].meal = time;
	}
	philo->param->ready = 1;
}

void	init_thread(t_philo *philo, t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->philo_nbr)
	{
		pthread_mutex_init(philo[i].forkl, NULL);
	}
	pthread_mutex_init(param->print, NULL);
	create_threads(philo);
	check_threds(philo);
}

void	init_philos(t_philo *philo, t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->philo_nbr)
	{
		philo[i].start = 0;
		philo[i].id = i + 1;
		philo[i].thread = 0;
		philo[i].meal = 0;
		philo[i].forkl = &param->forks[i];
		if (philo[i].id == param->philo_nbr)
			philo[i].forkr = &param->forks[0];
		else
			philo[i].forkr = &param->forks[i + 1];
		philo[i].param = param;
		philo[i].iter = 0;
	}
}
