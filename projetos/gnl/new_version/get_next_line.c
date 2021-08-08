#include "get_next_line.h"

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

void	get_line_size(t_buffer *buffer)
{
	int		desloc;
	size_t	size;

	size = 0;
	desloc = buffer->desloc;
	while (buffer->data[desloc + size] && buffer->data[desloc + size] != '\n')
		size++;
	if (buffer->data[desloc + size] == '\n')
		size++;
	buffer->line_size += size;
}

int		append_line(char *line, char *data)
{
	size_t	index;
	size_t	sub_index;

	index = 0;
	sub_index = 0;
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

void	update_line_size(t_buffer *buffer)
{
	size_t	size;

	size = 0;
	while (buffer->line[size])
		size++;
	buffer->line_size = size;
}


int		get_line(t_buffer *buffer)
{
	int	desloc;
	int	index;

	index = 0;
	get_line_size(buffer);
	buffer->tmp = (char *) ft_calloc(buffer->line_size + 1, sizeof(char));
	if (!buffer->tmp)
		return (0);
	if (buffer->line)
	{
		append_line(buffer->tmp, buffer->line);
		free(buffer->line);
	}
	desloc = append_line(buffer->tmp, &buffer->data[buffer->desloc]);
	buffer->line = buffer->tmp;
	update_line_size(buffer);
	buffer->tmp = 0;
	if (desloc == -1)
	{
		buffer->desloc = 0;
		while (buffer->data[index])
			buffer->data[index++] = 0;
		if ((read(buffer->fd, buffer->data, BUFFER_SIZE)) > 0)
			get_line(buffer);
	}
	else
		buffer->desloc += desloc;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_buffer	*begin;
	t_buffer		*buffer;

	buffer = get_buffer(&begin, fd);
	if (!buffer)
		return (0);
	if (!buffer->data)
		return (0);
	buffer->line = 0;
	buffer->line_size = 0;
	if (!get_line(buffer))
		return (0);
	if (*buffer->line == 0)
	{
		free(buffer->line);
		return (0);
	}
	return (buffer->line);
}