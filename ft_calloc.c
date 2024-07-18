/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:05:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/17 15:46:13 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp_str;
	size_t			i;

	tmp_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		tmp_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}