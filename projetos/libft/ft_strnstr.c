/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:45:34 by flavio            #+#    #+#             */
/*   Updated: 2021/07/28 20:33:17 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	index;
	size_t	sub_index;

	index = 0;
	sub_index = 0;
	if (*little == '\0')
		return (big);
	if (len == 0)
		return (0);
	while (big[index])
	{
		len--;
		while (little[sub_index])
			if (big[index + sub_index] == little[sub_index])
				sub_index++;
			else
				break ;
		if (sub_index == ft_strlen(little) && len + 1 >= ft_strlen(little))
			return (&big[index]);
		if (len == 0)
			return (0);
		sub_index = 0;
		index++;
	}
	return (0);
}
