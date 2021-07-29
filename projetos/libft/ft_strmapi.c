/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:12:23 by flavio            #+#    #+#             */
/*   Updated: 2021/07/29 14:15:14 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*string;

	size = ft_strlen(s);
	string = (char *) ft_calloc(size + 1, sizeof(char));
	while (size > 0)
	{
		string[size - 1] = f(size - 1, s[size - 1]);
		size--;
	}
	return (string);
}