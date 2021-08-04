#include "../test.h"

void	ft_putchar_fd_tester()
{
	title("ft_putchar");
	int	fd;
	char c;

	c = 0;
	fd = open("tmp_test.ft", O_WRONLY | O_CREAT,0764);
	ft_putchar_fd('F', fd);
	close(fd);

	fd = open("tmp_test.ft", O_RDONLY | O_CREAT,0764);
	read(fd, &c, 1);
	/*1*/check(c == 'F');
	/*2*/check(read(fd, &c, 1) == 0);
	unlink("tmp_test.ft");
	printf("\n");
}