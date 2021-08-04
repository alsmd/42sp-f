#include "../test.h"

void	ft_strlcpy_tester()
{
	title("ft_strlcpy");
	
	char	src[] ="hello world!";
	char	dest[30];
	/*1*/check(ft_strlcpy(dest, src, 13) == strlen(src));
	/*2*/check(!strncmp(src, dest, 13));
	bzero(dest, 30);
	dest[0]= 'Z';
	ft_strlcpy(dest, src, 0);
	/*3*/check(dest[0] == 'Z');
	bzero(dest, 30);
	dest[0] = 'A';
	ft_strlcpy(dest, "", 1);
	/*4*/check(dest[0] == 0);
	ft_strlcpy(dest, "1234", 4);
	/*5*/check(!strcmp(dest, "123"));
	printf("\n");
}
