#include "../test.h"

void	ft_toupper_tester()
{
	title("ft_toupper");

	check(ft_toupper('a') == 'A');
	check(ft_toupper('A') == 'A');
	check(ft_toupper('9') == '9');
	check(ft_toupper(0) == 0);
	printf("\n");
}