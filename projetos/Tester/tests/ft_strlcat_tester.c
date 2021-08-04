#include "../test.h"

void	ft_strlcat_tester()
{
	title("ft_strlcat");
	char	dest[30] = "hello ";
	char	src[30] = "World!";
	int		sizedest = ft_strlen(dest);

	/*1*/check(sizedest + strlen(src) == ft_strlcat(dest, src, 13) );
	/*2*/check(!strcmp(dest, "hello World!"));
	memset(dest, 0, 30);
	dest[0] = 'A';
	/*3*/check(ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "A"));
	memset(dest, 0, 30);
	dest[0] = 'B';dest[1] = 'A';dest[2] = 'T';dest[3] = 'T';dest[4] = 'A';
	/*4*/check(ft_strlcat(dest, src, 3) == strlen(src) + 3 && !strcmp(dest, "BATTA"));
	memset(dest, 0, 30);
	memset(dest, '1', 10);
	/*5*/check(ft_strlcat(dest, "", 15) == 10 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30);
	/*6*/check(ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""));
	printf("\n");
}
