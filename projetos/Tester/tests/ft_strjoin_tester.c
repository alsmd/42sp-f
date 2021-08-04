#include "../test.h"

void	ft_strjoin_tester()
{
	title("ft_strjoin");
	
	char	*str;
	char	*str2;
	char	*final;
	size_t	size;

	str = strdup("Hello ");
	str2 = strdup("World");
	size = strlen(str) + strlen(str2);
	final = ft_strjoin(str, str2);

	/*1*/check(strlen(final) == size);
	/*2*/check(!strcmp(final, "Hello World"));
	/*3*/mcheck(final, (size + 1) * sizeof(char));
	free(str);
	free(str2);
	free(final);
	//////////////////
	str = strdup("");
	str2 = strdup("");
	final = ft_strjoin(str, str2);

	/*4*/check(!strcmp(final, ""));
	/*5*/mcheck(final, 1 * sizeof(char));
	free(str);
	free(str2);
	free(final);
	printf("\n");
}
