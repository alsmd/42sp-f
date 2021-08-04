#include "../test.h"

static size_t	get_length(char	*str, char c)
{
	size_t		index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
//check if each string into **arr was created correctly with all words from str
static int verify_copy(char	**arr, char *str, char c)
{
	int	len;

	while (*str)
	{
		while (*str == c)
			str++;
		if (!*str)
			break ;
		len = get_length(str, c);
		if (strncmp(*arr, str, len))
			return (0);
		str += len;
		arr++;
	}
	return (1);
}
static void	free_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}
void	ft_split_tester()
{
	title("ft_split");
	char	s[] = "Uma bela de uma string separada por espaco";
	char	**arr;

	arr = ft_split(s, ' ');
	//[0]"uma"//[1]"bela"//[2]"de"//[3]"uma"//[4]"string"//[5]"separada"//[6]"por"//[7]"espaco"//[8]0
	/*1*/check(verify_copy(arr, s, ' '));
	/*2*/check(arr[8] == 0);
	/*3*/mcheck(arr, sizeof(char *) * (8 + 1));
	free_arr(arr);

	arr = ft_split("", ' ');
	/*4*/check(arr[0] == 0);
	/*5*/mcheck(arr, sizeof(char *) * 1);
	free_arr(arr);

	arr = ft_split("----------------------------------------------------", '-');
	/*6*/check(arr[0] == 0);
	/*7*/mcheck(arr, sizeof(char *) * 1);
	free_arr(arr);


	char	str[] = "------ banana  ------- ------batata-------------------------";
	arr = ft_split(str, '-');
	/*8*/check(verify_copy(arr, str, '-'));//[0]"" banana  "//[1]" "//[2]"batata"//[3]0
	/*9*/check(arr[3] == 0);
	/*10*/mcheck(arr, sizeof(char *) * 4);
	free_arr(arr);

	printf("\n");
}