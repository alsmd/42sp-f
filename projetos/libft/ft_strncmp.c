#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while ((s1[index] && s2[index]) && index < n)
	{
		if (s1[index] != s2[index] || index == n - 1)
			break ;
		index++;
	}
	return (s1[index] - s2[index]);
}
