#include <stdio.h>
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#define PRINT(string, ...) \
		char	buffer_1[1000]; \
		char	buffer_2[1000]; \
		int		r_1; \
		int		r_2; \
		bzero(buffer_1, 1000); \
		bzero(buffer_2, 1000); \
		redirect("tmp"); \
		r_1 = ft_printf(string, __VA_ARGS__); \
		lseek(1, 0, SEEK_SET); \
		read(1, buffer_1, 1000); \
		redirect("tmp2"); \
		r_2 = printf(string, __VA_ARGS__); \
		fflush(stdout); \
		lseek(1, 0, SEEK_SET); \
		read(1, buffer_2, 1000); \
		check(!(strcmp(buffer_1, buffer_2))); \
		check(r_1 == r_2); \
		unlink("tmp"); \
		unlink("tmp2"); \

static void	redirect(char *name)
{
	close(1);
	open(name, O_WRONLY);
}


int main(void)
{
	{
		PRINT("Hello World! %d", 10)
	}
	return (0);
}

