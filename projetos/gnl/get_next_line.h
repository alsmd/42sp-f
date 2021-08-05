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
	struct s_buffer	*next;
	
} t_buffer;

//BUFFER MANIPULATION
/*
	@param
	@brief

*/
char			*get_next_line(int fd);

/*
	@param
	@brief
	
*/
char			*fill_buffer(int fd);

/*
	@param
	@brief
	
*/
size_t			get_line_size(char	*data);

/*
	@param
	@brief
	
*/
int				append_line(char *line, char *data);

/*
	@param
	@brief
	
*/
void			get_line(t_buffer *buffer);

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