#include "../test.h"

void	ft_memmove_tester()
{
	title("ft_memmove");
	
	char	*dest = (char *) ft_calloc(30, sizeof(char));
	char	src[] = {'1', '2', 0, '4', '5', '6'};

	ft_memmove(dest, src, 5);
	/*1*/check(dest[0] == '1');
	/*2*/check(dest[2] == 0);
	/*3*/check(dest[4] == '5');
	/*4*/check(dest[5] == 0);
	memset(dest, 0, 30);
	ft_memmove(dest, src, 0);
	/*5*/check(dest[0] == 0);
	free(dest);
	//overflow dest > src
	char	tab[] = "123456789";//123456789
								//121234589
	ft_memmove(&tab[2], tab, 5);
	/*5*/check(!strcmp(tab, "121234589"));
	//overflow src > dest
	char	tab2[] = "123456789";//123456789
								//125678989
	ft_memmove(&tab2[2], &tab2[4], 5);
	/*5*/check(!strcmp(tab2, "125678989"));
	printf("\n");
}
