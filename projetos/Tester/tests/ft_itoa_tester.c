#include "../test.h"

void	ft_itoa_tester()
{
	title("ft_itoa");
	char	*string;

	string = ft_itoa(12345);
	/*1*/check(!strcmp(string, "12345"));
	/*2*/mcheck(string, 6 * sizeof(char));
	free(string);

	string = ft_itoa(-12345);
	/*3*/check(!strcmp(string, "-12345"));
	/*4*/mcheck(string, 7 * sizeof(char));
	free(string);

	string = ft_itoa(0);
	/*5*/check(!strcmp(string, "0"));
	/*6*/mcheck(string, 2 * sizeof(char));
	free(string);

	string = ft_itoa(2147483647);
	/*7*/check(!strcmp(string, "2147483647"));
	/*8*/mcheck(string, 11 * sizeof(char));
	free(string);

	string = ft_itoa(-2147483648);
	/*9*/check(!strcmp(string, "-2147483648"));
	/*10*/mcheck(string, 12 * sizeof(char));
	free(string);
	printf("\n");
}