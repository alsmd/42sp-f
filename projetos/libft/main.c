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
	char	**array;
	char	*splitme;

	splitme = strdup(" Tripouille ");
	array = ft_split(splitme, ' ');

	printf("%d", strcmp("Tripouille", array[0]));
	/* while (array[index])
	{
		printf("%s\n", array[index]);
		index++;
	} */
	return (0);
}