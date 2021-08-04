#include "../test.h"

void	ft_tolower_tester()
{
	title("ft_tolower");

	check(ft_tolower('a') == 'a');
	check(ft_tolower('A') == 'a');
	check(ft_tolower('9') == '9');
	check(ft_tolower(0) == 0);
	printf("\n");
}
