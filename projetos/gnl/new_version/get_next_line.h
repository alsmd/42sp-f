#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
//////////////////
#include <string.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
typedef struct s_buffer
{
	int				fd;
	char			*data;
	int				desloc;
	char			*line;
	char			*tmp;
	size_t			line_size;
	struct s_buffer	*next;
	
} t_buffer;

//BUFFER MANIPULATION
/*
	@param
	@brief

*/
char			*get_next_line(int fd);

/*
	@param fd		File Descriptor Used.
	@brief			Get "n" character from the File Descriptor
					fd and return this buffer with these characters.
	@return			Buffer with the fd's content or 0 if the 
					allocation failed, or if it was not possible
					to read from the fd, or if there is nothing 
					more to be read from it.
*/
char			*fill_buffer(int fd);

/*
	@param buffer	A t_buffer pointer that contains informations about
					the buffer of the currently fd.
	@brief			Get the size of the line that is on buffer->data.
					the size is start from buffer->data[buffer->desloc].
					The size is stored on buffer->line_size.
*/
void		get_line_size(t_buffer *buffer);

/*
	@param
	@brief
	
*/
int				append_line(char *line, char *data);

/*
	@param buffer	A t_buffer pointer that contains informations about
					the buffer of the currently fd.
	@brief			Get the line from buffer->data starting on index
					buffer->desloc and store on buffer->line.
					buffer->tmp is used to manage the data.
*/
int			get_line(t_buffer *buffer);

//LIST MANIPULATION
/*

*/
t_buffer		*get_buffer(t_buffer **begin, int fd);

/*
	@param
	@brief
	
*/
t_buffer		*ft_lstadd(t_buffer **begin, t_buffer *buffer);

/*
	@param
	@brief
	
*/
t_buffer		*ft_lstnew(int	fd);

//UTILITIES
/*

*/
void			*ft_calloc(size_t nmemb, size_t size);
#endif