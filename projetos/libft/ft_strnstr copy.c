#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	index;
	size_t	sub_index;
	size_t	tmp;

	index = 0;
	sub_index = 0;
	while (big[index])
	{
		while (little[sub_index])
		{	
			if (len == 0)
				break ;
			len--;
			tmp = len;
			if (big[index + sub_index] == little[sub_index])
				sub_index++;
			else
				break ;
		}
		if (sub_index == ft_strlen(little))
			return (&big[index]);
		else
			len = tmp - 1;
		if (len == 0)
			return (0);
		sub_index = 0;
		index++;
	}
	return (0);
}
