#include "../test.h"

//if n is odd and c is in lowercase we return c in uppercase
static void	to_upper_odd(unsigned int n, char *c)
{
	if (n % 2 != 0)
		if (*c >= 95 && *c <= 122)
			*c -= 32;
}

void	ft_striteri_tester()
{
	title("ft_striteri");
	char	string[] = "string linda!!";

	ft_striteri(string, to_upper_odd);
	/*1*/check(!strcmp(string, "sTrInG LiNdA!!"));
	char	string2[] = "";
	ft_striteri(string2, to_upper_odd);
	/*2*/check(!strcmp(string2, ""));
	printf("\n");
}