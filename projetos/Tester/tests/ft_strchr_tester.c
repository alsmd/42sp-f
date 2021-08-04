#include "../test.h"

void	ft_strchr_tester()
{
	title("ft_strchr");
	char	tab[50] = "Geral estudando! isso ai.";
	/*1*/check(&tab[7] == ft_strchr(tab, 's'));
	/*2*/check(0 == ft_strchr(tab, 'z'));
	/*3*/check(&tab[25] == ft_strchr(tab, '\0'));
	printf("\n");
}
