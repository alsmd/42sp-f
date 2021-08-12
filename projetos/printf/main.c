#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*t ="555";
	//printf("%.12dm\n", ft_atoi("123"));
	//printf("%010st\n", "ola");
	//ft_printf("%0-10.10000st\n", "ola");
	ft_printf("%.7p\n", t);
	printf("%.7p\n", "t");
	//printf("%p\n", "555");
	return (0);
}
