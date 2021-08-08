#include "get_next_line.h"
extern int errno;

char	*fill_buffer(int fd)
{
	char	*tmp;
	int		r;

	tmp = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (0);
	r = read(fd, tmp, BUFFER_SIZE);
	if (r <= 0)
	{
		free(tmp);
		return (0);
	}
	tmp[r] = '\0';
	return (tmp);
}

size_t	get_line_size(char	*data)
{
	size_t	size;

	size = 0;
	while (data[size] && data[size] != '\n')
		size++;
	if (data[size] == '\n')
		size++;
	return (size);
}

int	append_line(char *line, char *data)
{
	int		index;
	int		sub_index;

	sub_index = 0;
	index = 0;
	while (line[index])
		index++;
	while (data[sub_index])
	{
		line[index + sub_index] = data[sub_index];
		if (data[sub_index] == '\n')
			return (sub_index + 1);
		sub_index++;
	}
	return (-1);
}

void	get_line(t_buffer *buffer)
{
	size_t	size;
	char	*tmp;
	int		desloc;

	size = get_line_size(&buffer->data[buffer->desloc]);
	if (buffer->line)
		size += get_line_size(buffer->line);
	tmp = (char *) ft_calloc(size + 1, sizeof(char));
	if (buffer->line)
		append_line(tmp, buffer->line);
	desloc = append_line(tmp, &buffer->data[buffer->desloc]);
	if (buffer->line)
		free(buffer->line);
	buffer->line = tmp;
	if (desloc == -1)
	{
		free(buffer->data);
		buffer->data = fill_buffer(buffer->fd);
		buffer->desloc = 0;
		if (buffer->data != 0)
			get_line(buffer);
	}
	else
		buffer->desloc += desloc;
}

char	*get_next_line(int fd)
{
	static t_buffer	*begin;
	t_buffer		*buffer;

	buffer = get_buffer(&begin, fd);
	
	if (buffer->data == 0 && !(buffer->data = fill_buffer(fd)))
		return (0);
	if (buffer->line)
		buffer->line = 0;
	get_line(buffer);
	if (buffer->line[0] == 0)
	{
		free(buffer->line);
		return (0);
	}
	return (buffer->line);
}

/* int	main(void)
{
	int	fd;
	char	*tmp;

	fd = open("./files/43_with_nl", O_RDONLY);

	while ((tmp = get_next_line(fd)))
	{
		printf("%s", tmp);
		free(tmp);
	}

	if (errno)
		printf("%s", strerror(errno));
	return (0);
} */