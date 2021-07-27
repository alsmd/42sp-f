#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dest > src)
	{
		while (n >= 1)
		{
			((unsigned char *) dest)[n - 1] = ((unsigned char *) src)[n - 1];
			n--;
		}
	}
	else if (dest < src)
	{
		while (index < n)
		{
			((char *) dest)[index] = ((unsigned char *) src)[index];
			index++;
		}
	}
	return (dest);
}
