/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/25 15:29:40 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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