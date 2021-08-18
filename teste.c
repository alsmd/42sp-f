#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

size_t	ft_strlen(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (dstsize > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		dstsize--;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	tot_size;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tot_size = (len_s1 + len_s2 + 1);
	new = (char *)malloc(tot_size * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, (len_s1 + 1));
	ft_strlcpy(&new[len_s1], s2, (len_s2 + 1));
	return (new);
}

char	*get_line(int fd, int BUFFER_SIZE)
{
	char			*read_buff;
	int				flag;
	char			*line_x;
	static char		*line_y;
	int		i;
	int		j;

	if (!fd)
		return (NULL);
	read_buff = (char *)malloc(sizeof(BUFFER_SIZE));
	if (!read_buff)
		return (NULL);
	line_x = (char *)malloc(sizeof(BUFFER_SIZE));
	if (!line_x)
		return (0);
	flag = 0;
	i = 0;
	j = 0;
	if (line_y)
	{
		while (line_y[i] != '\0')
		{

			if (line_y[i] == '\n')
			{
				line_x[i] = line_y[i];
				while (line_y[i] != '\0')
				{
					line_y[j] = line_y[i +1];
					i++;
					j++;
				}
				return (line_x);
			}
			line_x[i] = line_y[i];
			i++;
		}
	}

	while (flag == 0)
	{
		read(fd, read_buff, BUFFER_SIZE);
		i  = 0;
		while(i < BUFFER_SIZE)
		{
			if(read_buff[i] == '\n' || read_buff[i] == '\0')
			{
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0)
		{
			line_x = ft_strjoin(line_x, read_buff);
		}


		if (flag == 1)
		{
			line_y = (char *)malloc(sizeof(BUFFER_SIZE));
			if (!line_y)
				return (0);
			j = 0;
			while ( j <= i)
			{
				line_y[j] = read_buff[j];
				j++;
			}
			line_x = ft_strjoin(line_x, line_y);
			j = 0;

			if (read_buff[i] == '\n')
			j = 0;
			i = i + 1;
			while (i < BUFFER_SIZE)
			{
				line_y[j] = read_buff[i];
				i++;
				j++;
			}
			line_y[j] = '\0';
			return (line_x);
		}
		
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file", O_RDONLY);
	while ((line = get_line(fd, 3)))
		printf("%s", line);
	return (0);
}