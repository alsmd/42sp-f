/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:45:36 by flavio            #+#    #+#             */
/*   Updated: 2021/07/28 19:45:37 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	long int	index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == ((char)c))
			return (&s[index]);
		index--;
	}
	return (0);
}
