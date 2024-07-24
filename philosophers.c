/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/24 15:43:18 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_param *parse_line(char **argv)
{
	t_param *param;

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
	param->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		param->eat_count = ft_atoi(argv[5]);
	param->philo_nbr = ft_atoi(argv[1]);
	return (param);
}

void ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	print(p, 1);
	pthread_mutex_lock(p->forkr);
	print(p, 6);
	p->last_eat = current_time();
	p->iter++;
	print(p, 2);
	ft_unsleep(p->param->eat_time);
	pthread_mutex_unlock(p->forkl);
	pthread_mutex_unlock(p->forkr);
}
void *routine (void *phil)
{
	t_philo *p;

	p = (t_philo *)phil;
	while (!(p->ready))
		continue;
	if (p->id %2)
		ft_usleep(p->param->eat_time * 0.9 + 1);
	while(!(p->over))
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
		// print(p, 3)
		ft_unsleep(p->param->sleep_time);
		// print(p, 4);
	}
	return(NULL);
}

void create_threads(t_philo *philo)
{
	int i;
	long int time;

	i = 0;
	time = get_time();
	while(i <= philo->param->philo_nbr)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	
}

void init_thread(t_philo *philo, t_param *param)
{
	int i;

	i = 0;
	while (i <= philo->param->philo_nbr)
	{
		pthread_mutex_init(philo[i].forkl, NULL);
		i++;
	}
	pthread_mutex_init(param->print, NULL);
	create_threads(philo);
	
}

void init_philos(t_philo *philo, t_param *param)
{
	int i;

	i = 0;
	while (i < param->philo_nbr)
	{
		philo[i].id = i;
		philo[i].iter = 0;
		philo[i].last_eat = 0;
		philo[i].param = param;
		philo[i].forkl = &param->forks[i];
		if (philo[i].id == param->philo_nbr )
			philo[i].forkr = &param->forks[0];
		else
			philo[i].forkr = &param->forks[i + 1];
		i++;
		philo[i].param = param;
		philo[i].iter = 0;
	}
}

int main(int argc, char **argv)
{
	t_philo *philo;
	t_param *param;

	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	param = parse_line(argv);
	init_philos(philo, param);
	inti_threads(philo, param);
	// init_philos(philo);
}