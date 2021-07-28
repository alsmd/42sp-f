#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	s1len;
	size_t	s2len;
	size_t	size;

	if (s1 == 0 || s2 == 0)
		return ((char *) ft_calloc(1, sizeof(char)));
	else
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		size = s1len + s2len;
	}
	string = (char *) ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string, s1, s1len + 1);
	ft_strlcat(string, s2, s1len + s2len + 1);
	return (string);
}
