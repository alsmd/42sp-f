#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("teste", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);

	return (0);
}
