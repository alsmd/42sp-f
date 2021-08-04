#include "../test.h"

void	ft_strrchr_tester()
{
	title("ft_strrchr");
	char	tab[50] = "Geral estudando! isso ai.";

	/*1*/check(&tab[19] == ft_strrchr(tab, 's'));
	/*2*/check(0 == ft_strrchr(tab, 'z'));
	/*3*/check(&tab[25] == ft_strrchr(tab, '\0'));
	printf("\n");
}
