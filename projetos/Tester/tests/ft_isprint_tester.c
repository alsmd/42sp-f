#include "../test.h"

void	ft_isprint_tester()
{
	title("ft_isprint");

	check(ft_isprint(126));
	check(ft_isprint(50));
	check(ft_isprint(32));
	check(!ft_isprint(31));
	check(!ft_isprint(127));
	check(!ft_isprint(0));
	printf("\n");
}
