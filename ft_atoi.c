/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:42:41 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/17 15:47:28 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	algorythm(const char *str, size_t i, int result, int minus)
{
	while (i < ft_strlen(str))
	{
		if ((!(str[i] >= 48 && str[i] <= 57))
			&& (str[i] != '\f' && str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\r' && str[i] != '\v'
				&& str[i] != '-' && str[i] != '+' && str[i] != ' '))
			break ;
		if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
			minus = -1;
		if (str[i] == '-' || str[i] == '+')
		{
			if (result != 0 || (str[i + 1] < '0' || str[i + 1] > '9'))
				break ;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				break ;
		}
		else if (result != 0)
			break ;
		i++;
	}
	return (result * minus);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		minus;
	size_t	i;

	i = 0;
	minus = 1;
	result = 0;
	return (algorythm(str, i, result, minus));
}