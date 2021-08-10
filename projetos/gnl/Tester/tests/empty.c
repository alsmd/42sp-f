#include "../test.h"

void	empty()
{
	title("empty: ");
	int	fd;

	fd = open("../files/empty", O_RDONLY);

	check(get_next_line(fd) == 0);

	close(fd);
	printf("\n");
}