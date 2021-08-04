#include "../test.h"

void	ft_atoi_tester()
{
	title("ft_atoi");

	/*1*/check(ft_atoi("1234vasd123") == 1234);
	/*2*/check(ft_atoi("-1234aszx415") == -1234);
	/*3*/check(ft_atoi("+1234htfd2347") == 1234);
	/*4*/check(ft_atoi("--1234zxv789") == 0);
	/*5*/check(ft_atoi("-+1234dsad13") == 0);
	/*6*/check(ft_atoi("  \t\f\v\r\n555asddsa135") == 555);
	/*7*/check(ft_atoi("  \t\f\v\r\n-555-5664") == -555);
	/*8*/check(ft_atoi("Nota 10") == 0);
	printf("\n");
}
