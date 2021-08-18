#include <stdio.h>
#include "include/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	redirect(char *name)
{
	close(1);
	open(name, O_WRONLY);
}

int main(void)
{
	int	number;

	//ft_printf("% +#-3.5c", 'A');
	return (0);
}

