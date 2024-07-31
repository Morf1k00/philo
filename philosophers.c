/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/31 14:10:49 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_param	*param;

	if (argc < 4 || argc > 5)
	{
		error_print();
		return (1);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	param = parse_line(argv);
	init_philos(philo, param);
	init_thread(philo, param);
	join_threads(philo);
	free_all(philo);
}
