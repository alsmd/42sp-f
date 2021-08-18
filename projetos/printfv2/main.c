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
	ft_printf("%+5.3d ola mundo\n", 10);
	printf("%.3d ola mundo", -10);
	return (0);
}

