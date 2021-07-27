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
