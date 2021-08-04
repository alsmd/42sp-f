#include "../test.h"

void	ft_putnbr_fd_tester()
{
	title("ft_putnbr_fd");

	int	fd;
	char	buffer[100];
	/********MAX VALUE INT****/
	fd = open("tmp_test3.ft", O_WRONLY | O_CREAT,0764);
	ft_putnbr_fd(2147483647, fd);
	close(fd);

	fd = open("tmp_test3.ft", O_RDONLY);
	read(fd, buffer, 10);
	buffer[10] = 0;
	/*1*/check(!strcmp(buffer, "2147483647"));
	/*2*/check(!read(fd, &buffer[50], 1)); //check if you wrote more than the necessary
	close(fd);
	unlink("tmp_test3.ft");

	/********MIN VALUE INT****/
	fd = open("tmp_test3.ft", O_WRONLY | O_CREAT,0764);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);

	fd = open("tmp_test3.ft", O_RDONLY);
	read(fd, buffer, 11);
	buffer[11] = 0;
	/*1*/check(!strcmp(buffer, "-2147483648"));
	/*2*/check(!read(fd, &buffer[50], 1)); //check if you wrote more than the necessary
	close(fd);
	unlink("tmp_test3.ft");
	printf("\n");
}