/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:16:19 by flavio            #+#    #+#             */
/*   Updated: 2021/08/09 10:33:47 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	index;

	index = 0;
	if (nmemb * size > INT_MAX)
	{
		errno = 12;
		return (0);
	}
	r = malloc(nmemb * size);
	if (r)
	{
		while (index < nmemb * size)
			((char *)r)[index++] = 0;
		return (r);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((char *)s)[n] = 0;
}
