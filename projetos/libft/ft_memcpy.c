#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n > 0)
	{
		((char *) dest)[n - 1] = ((unsigned char *) src)[n - 1];
		n--;
	}
	return (dest);
}
