#include "../test.h"

void	ft_strnstr_tester()
{
	title("ft_strnstr");

	char	tab[] = "Fala minha galera linda do meu coracao";
	

	/*1*/check(&tab[5] == ft_strnstr(tab, "minha", 10));
	/*2*/check(0 == ft_strnstr(tab, "minha", 9));
	/*3*/check(tab == ft_strnstr(tab, "", 1233));
	/*4*/check(0 == ft_strnstr(tab, "zago", 10000));
	/*5*/check(tab == ft_strnstr(tab, "", 0));
	/*6*/check(&tab[18] == ft_strnstr(tab, "lin", 21));
	/*7*/check(0 == ft_strnstr(tab, "lin", 20));
	/*8*/check(0 == ft_strnstr(tab, "Fala", 0));
	printf("\n");
}
