#include "../test.h"

void	ft_isascii_tester()
{
	title("ft_isascii");
	check(ft_isascii(0));
	check(ft_isascii(123));
	check(ft_isascii(127));
	check(!ft_isascii(128));
	check(!ft_isascii(1152));
	check(!ft_isascii(-10));
	printf("\n");
}