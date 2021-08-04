#include "../test.h"

//if n is odd and c is in lowercase we return c in uppercase
static char	to_upper_odd(unsigned int n, char c)
{
	if (n % 2 != 0)
		if (c >= 95 && c <= 122)
			c -= 32;
	return (c);
}

void	ft_strmapi_tester()
{
	title("ft_strmapi");

	char	*string = "string linda!!";
	char	*cpy;
	//char	(*f)(unsigned int, char) = to_upper_odd;
	cpy = ft_strmapi(string, to_upper_odd);
	/*1*/check(!strcmp(cpy, "sTrInG LiNdA!!"));
	/*2*/mcheck(cpy, (strlen(string) + 1) * sizeof(char));
	free(cpy);

	cpy = ft_strmapi("", to_upper_odd);
	/*3*/check(!strcmp(cpy, ""));
	/*4*/mcheck(cpy, 1 * sizeof(char));
	free(cpy);
	printf("\n");
}