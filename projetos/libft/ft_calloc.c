#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

extern int	errno;

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (nmemb * size > INT_MAX)
		errno = 12;
		return (0);
	if ((r = malloc(nmemb * size)))
	{
		ft_memset(r, 0, nmemb * size);
		return (r);
	}
	return (0);
}
