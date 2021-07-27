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
	char haystack[] = "123456124";

	printf("%s\n", ft_substr(haystack, 10, 7));
	return (0);
}