#include "../test.h"

void	ft_putstr_fd_tester()
{
	title("ft_putstr_fd");
	int	fd;
	char	buffer[100];

	fd = open("tmp_test1.ft", O_WRONLY | O_CREAT,0764);
	ft_putstr_fd("Hello World!", fd);
	close(fd);

	fd = open("tmp_test1.ft", O_RDONLY);
	read(fd, buffer, 12);
	buffer[12] = 0;
	/*1*/check(!strcmp(buffer, "Hello World!"));
	/*2*/check(!read(fd, &buffer[50], 1)); //check if you wrote more than the necessary
	close(fd);
	unlink("tmp_test1.ft");
	printf("\n");
}
