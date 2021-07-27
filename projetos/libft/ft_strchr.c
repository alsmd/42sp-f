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
