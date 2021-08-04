#include "../test.h"

void	ft_isalnum_tester()
{
	title("ft_isalnum");
	check(ft_isalnum('a'));
	check(ft_isalnum('z'));
	check(ft_isalnum('A'));
	check(ft_isalnum('Z'));
	check(ft_isalnum('1'));
	check(!ft_isalnum(0));
	check(!ft_isalnum(255));
	check(!ft_isalnum('!'));
	printf("\n");
}