#include "libft.h"

static size_t	is_in(const char *array, char c)
{
	size_t	index;

	index = 0;
	while (array[index])
	{
		if (array[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static size_t	get_size(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	index;

	start = 0;
	end = ft_strlen(s) - 1;
	index = 0;
	while (is_in(set, s[start]))
		start++;
	while (is_in(set, s[end]))
		end--;
	while (start <= end)
	{
		start++;
		index++;
	}
	return (index);
}

static void	set_string(const char *set, char *str, const char *s)
{
	size_t	start;
	size_t	end;
	size_t	index;

	start = 0;
	end = ft_strlen(s) - 1;
	index = 0;
	while (is_in(set, s[start]))
		start++;
	while (is_in(set, s[end]))
		end--;
	while (start <= end)
	{
		str[index] = s[start];
		start++;
		index++;
	}
	str[index] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	size;

	size = get_size(s1, set);
	string = (char *) ft_calloc(size + 1, sizeof(char));
	set_string(set, string, s1);
	return (string);
}
