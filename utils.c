/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:05:30 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/24 15:44:27 by rkrechun         ###   ########.fr       */
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