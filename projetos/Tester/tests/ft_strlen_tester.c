#include "../test.h"

void	ft_strlen_tester()
{
	title("ft_strlen");

	/*1*/check(ft_strlen("ola meu increvel mundo") == strlen("ola meu increvel mundo"));
	/*2*/check(ft_strlen("") == 0);
	/*3*/check(ft_strlen("cac\0csacs") == 3);
	printf("\n");
}
