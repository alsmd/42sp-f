#include "../test.h"

void	ft_memset_tester()
{
	title("ft_memset");
	char	*tab;
	int		i;
	tab = (char *) ft_calloc(100, sizeof(char));
	ft_memset(tab, 'A', 50);
	/*1*/check(tab[0] == 'A');
	/*2*/check(tab[25] == 'A');
	/*3*/check(tab[50] != 'A');
	free(tab);
	tab = (char *) ft_calloc(100, sizeof(char));
	ft_memset(tab, 'Z', 30);
	for(i = 0; tab[i] == 'Z' && i < 29; i++)
		;
	/*4*/check(i == 29 && tab[29] == 'Z');
	free(tab);
	int		*ptr;
	ptr = (int *) ft_calloc(1, sizeof(int));
	*ptr = 35528;
	//change the last byte of a integer of 4 bytes
	//
	//00000000 00000000 10001010 11001000 = 35528
	//10000010  = 130
	//00000000 00000000 10001010 10000010 = 35458
	ft_memset(ptr, 130, 1);
	/*4*/check(*ptr == 35458);
	free(ptr);
	printf("\n");
}
