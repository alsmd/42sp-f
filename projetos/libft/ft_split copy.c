#include "libft.h"
#include <stdio.h>
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

	while (s[desloc] == c)//----ola---minha-gente
		desloc++;
	size = get_length(&s[desloc], c);
	string = ft_substr(s, desloc, size);
	desloc += size;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	index;
	char	**array;

	index = 0;
	size = get_size(s, c);
	array = (char **) ft_calloc(size + 1, sizeof(char *));
	while (index < size)
	{
		array[index] = next_str(s, c);
		index++;
	}
	array[index] = 0;
	return (array);
}
