/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:29 by flavio            #+#    #+#             */
/*   Updated: 2021/07/28 19:44:30 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t	index;
	size_t	size;

	size = ft_strlen(s);
	index = 0;
	while (index <= size)
	{
		if (s[index] == ((char)c))
			return (&s[index]);
		index++;
	}
	return (0);
}
