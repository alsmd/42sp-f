#include "../test.h"

void	ft_bzero_tester()
{
	title("ft_bzero");

	char *tab;

	tab = strdup("1123456789m");
	int	i;
	ft_bzero(tab, 0);
	/*1*/check(tab[0] == '1');
	ft_bzero(tab, 10);
	for(i = 0; i < 10 && tab[i] == 0; i++)
		;
	/*2*/check(tab[5] == 0);
	/*3*/check(i == 10 && tab[10] == 'm');
	free(tab);
	printf("\n");
}
