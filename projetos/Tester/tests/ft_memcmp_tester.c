#include "../test.h"

void	ft_memcmp_tester()
{
	title("ft_memcmp");

	/*1*/check(!ft_memcmp("1234", "1234", 4));//equal
	/*2*/check(!ft_memcmp("123Z", "123A", 3));//equal
	/*3*/check(!ft_memcmp("asdfv", "cadsac", 0));//diferent but 0 to compare
	/*4*/check(ft_memcmp("1234", "1232", 4) > 0);//first memory area's value is higher
	/*5*/check(ft_memcmp("1232", "1234", 4) < 0);//first memory area's value is lower
	
	//we are not really comparing string, so even if a null is found
	//we keep going with the comparations.
	/*6*/check(ft_memcmp("abcd\0a", "abcd\0A", 6) != 0);
	printf("\n");
}
