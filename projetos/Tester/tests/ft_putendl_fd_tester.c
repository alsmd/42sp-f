#include "../test.h"

void	ft_putendl_fd_tester()
{
	title("ft_putendl_fd");

	int	fd;
	char	buffer[100];

	fd = open("tmp_test2.ft", O_WRONLY | O_CREAT,0764);
	ft_putendl_fd("Hello World!", fd);
	close(fd);

	fd = open("tmp_test2.ft", O_RDONLY);
	read(fd, buffer, 13);
	buffer[13] = 0;
	/*1*/check(!strcmp(buffer, "Hello World!\n"));
	/*2*/check(!read(fd, &buffer[50], 1)); //check if you wrote more than the necessary
	close(fd);
	unlink("tmp_test2.ft");
	printf("\n");
}