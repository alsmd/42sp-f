#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	find;
	size_t			index;

	index = 0;
	find = c;
	temp = s;
	while (index < n)
	{
		if (temp[index] == find)
			return (&temp[index]);
		index++;
	}
	return (0);
}
