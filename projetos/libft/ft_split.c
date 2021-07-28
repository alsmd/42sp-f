/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:27 by flavio            #+#    #+#             */
/*   Updated: 2021/07/28 19:44:27 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_size(char const *s, char c)
{
	size_t		size;
	short int	str_found;

	str_found = 0;
	size = 0;
	if (!s[0])
		return (0);
	while (1)
	{
		if ((*s == c || *s == '\0') && str_found)
		{
			size++;
			str_found = 0;
		}
		else if (*s != c)
			str_found = 1;
		if (*s == '\0')
			break ;
		s++;
	}
	return (size);
}

static size_t	get_length(char const *s, char c)
{
	size_t		index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	return (index);
}

static char	*next_str(char const *s, char c)
{
	size_t			size;
	static size_t	desloc;
	char			*string;

	while (s[desloc] == c)
		desloc++;
	size = get_length(&s[desloc], c);
	string = ft_substr(s, desloc, size);
	desloc += size;
	return (string);
}

void	malloc_error(char	**array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	index;
	char	**array;

	index = 0;
	size = get_size(s, c);
	array = (char **) ft_calloc(size + 1, sizeof(char *));
	if (!array)
		return (0);
	while (index < size)
	{
		array[index] = next_str(s, c);
		if (!array[index])
			malloc_error(array, size);
		index++;
	}
	array[index] = 0;
	return (array);
}
