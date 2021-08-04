#include "../test.h"

void	ft_calloc_tester()
{
	title("ft_calloc");

	int	*arr;
	arr = (int *) ft_calloc(4, sizeof(int));
	int	re[] = {0, 0, 0, 0};

	/*1*/check(!memcmp(arr, re, sizeof(int) * 4));
	/*2*/mcheck(arr, sizeof(int) * 4);

	free(arr);

	printf("\n");
}
