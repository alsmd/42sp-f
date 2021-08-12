#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	//printf("%.12dm\n", ft_atoi("123"));
	//printf("%010st\n", "ola");
	//ft_printf("%0-10.10000st\n", "ola");
	ft_printf("%+d-%+d %+s\n", 42, 24, "Everything is fine");
	//printf("%3.3dt\n", 42);
	return (0);
}
