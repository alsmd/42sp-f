#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	while (*string)
	{
		write(1, string, 1);
		string++;
	}
	return (0);
}
