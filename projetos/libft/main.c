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
	char haystack[30] = "123456124";

	printf("%s\n", strnstr(haystack, "", 9));
	printf("%s\n", ft_strnstr(haystack, "", 9));
	printf("%p\n",haystack);
	return (0);
}