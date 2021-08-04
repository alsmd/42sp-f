#include "../test.h"

void	ft_memchr_tester()
{
	title("ft_memchr");
	char	*string = "ola minha  familia linda!";

	/*1*/check(&string[11] == ft_memchr(string, 'f', 12));
	/*2*/check(0 == ft_memchr(string, 'f', 11));
	/*3*/check(0 == ft_memchr(string, 'o', 0));
	/*4*/check(&string[25] == ft_memchr(string, 0, 26));// We are comparing bytes, so the null-termineted is included
	/*5*/check(&string[0] == ft_memchr(string, 256 + 111, 1));// has to convert to unsigned char
	/*6*/check(&string[11] == ft_memchr(string, 'f', 123112312312312123));

	printf("\n");
}