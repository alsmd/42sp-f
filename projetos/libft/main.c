#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <bsd/string.h>

extern int errno;

int	main(void)
{
	printf("%s\n", ft_strtrim("---- ---ola mundo--- ----", "- "));
	return (0);
}