#include "../test.h"

void	ft_memcpy_tester()
{
	title("ft_memcpy");
	char	*dest = (char *) ft_calloc(30, sizeof(char));
	char	src[] = {'1', '2', 0, '4', '5', '6'};

	ft_memcpy(dest, src, 5);
	/*1*/check(dest[0] == '1');
	/*2*/check(dest[2] == 0);
	/*3*/check(dest[4] == '5');
	/*4*/check(dest[5] == 0);
	memset(dest, 0, 30);
	ft_memcpy(dest, src, 0);
	/*5*/check(dest[0] == 0);
	free(dest);
	char	tab[] = "123456789";//123456789
								//121234589
	ft_memcpy(&tab[2], tab, 5);
	/*5*/check(!strcmp(tab, "121234589"));
	/*6*/check(ft_memcpy(0, 0, 10) == 0);
	printf("\n");
}
