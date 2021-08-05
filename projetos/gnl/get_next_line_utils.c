#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	index;

	index = 0;
	if (nmemb * size > INT_MAX)
	{
		errno = 12;
		return (0);
	}
	r = malloc(nmemb * size);
	if (r)
	{
		while (index < nmemb * size)
			((char *)r)[index++] = 0;
		return (r);
	}
	return (0);
}



t_buffer	*ft_lstadd(t_buffer **begin, t_buffer *buffer)
{
	t_buffer	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = buffer;
	}
	else
		*begin = buffer;
	return (buffer);
}

t_buffer	*get_buffer(t_buffer **begin, int fd)
{
	t_buffer	*tmp;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (ft_lstadd(begin, ft_lstnew(fd)));
}

t_buffer	*ft_lstnew(int	fd)
{
	t_buffer	*tmp;

	tmp	= (t_buffer *) ft_calloc(1, sizeof(t_buffer));
	tmp->fd = fd;
	tmp->data = fill_buffer(fd);
	return (tmp);
}