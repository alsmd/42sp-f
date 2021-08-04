#include "../test.h"

void	ft_isalpha_tester()
{
	title("ft_isalpha");

	check(ft_isalpha('a'));
	check(ft_isalpha('z'));
	check(ft_isalpha('A'));
	check(ft_isalpha('Z'));
	check(!ft_isalpha(1));
	check(!ft_isalpha(255));
	check(!ft_isalpha(-255));
	printf("\n");
}