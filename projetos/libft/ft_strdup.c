#include "libft.h"
#include <errno.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	size;
	size_t	index;

	index = 0;
	size = ft_strlen(s) + 1;
	cpy = (char *) malloc(size);
	if (!(cpy))
		return (0);
	while (s[index])
	{
		cpy[index] = s[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}
