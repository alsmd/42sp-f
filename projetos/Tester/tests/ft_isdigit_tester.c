#include "../test.h"

void	ft_isdigit_tester()
{
	title("ft_isdigit");
	check(ft_isdigit('0'));
	check(ft_isdigit('1'));
	check(!ft_isdigit('9' + 1));
	check(!ft_isdigit('0' - 1));
	check(!ft_isdigit(255));
	check(!ft_isdigit(0));
	printf("\n");
}
