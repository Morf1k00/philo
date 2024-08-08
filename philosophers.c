/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/08/08 15:55:53 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_para(t_param *param)
{
	free(param->print);
	free(param->forks);
	free(param);
}

void	error_num(int err_n, t_param *param)
{
	if (err_n == 0)
		printf("Error in mutex initialization\n");
	else if (err_n == 1)
		printf("Error in thread creation\n");
	free_para(param);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_param	*param;

	if (argc < 4 || argc > 6)
	{
		error_print();
		return (1);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (philo == NULL)
		return (1);
	param = malloc(sizeof(t_param));
	if (param == NULL)
	{
		free(philo);
		return (1);
	}
	parse_line(argv, param);
	init_philos(philo, param);
	init_thread(philo, param);
	join_threads(philo);
	free_all(philo);
}
