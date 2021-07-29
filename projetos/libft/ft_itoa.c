/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:13:35 by flavio            #+#    #+#             */
/*   Updated: 2021/07/29 12:23:53 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	index;

	index = 0;
	while (n)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*string;

	size = get_size(n);
	string = (char *) ft_calloc(size + 1, sizeof(char));
}
