#include "../test.h"

void	ft_strncmp_tester()
{
	title("ft_strncmp");
	int		a[] = {500, '\0'};
	int		b[] = {256, '\0'};

	/*1*/check(!ft_strncmp("ola", "ola", 4));
	/*2*/check(!ft_strncmp("alohi", "aloha", 3));
	/*3*/check(ft_strncmp("trab", "higu", 10) > 0);
	/*4*/check(ft_strncmp("hrab", "tigu", 10) < 0);
	/*5*/check(ft_strncmp((char *)a, (char *)b, 1) > 0);
	printf("\n");
}
