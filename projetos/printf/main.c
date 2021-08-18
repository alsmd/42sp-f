#include <stdio.h>
#include "ft_printf.h"
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
	char *t = "555";
	int number;

	//redirect("a");
	//ft_printf("%pdoideira\n", 5);
	printf("%.3d", -10);
	return (0);
}

