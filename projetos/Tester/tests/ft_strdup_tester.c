#include "../test.h"

void	ft_strdup_tester()
{
	title("ft_strdup");

	char	*s = "Eu dupliquei essa string linda!";
	char	*str;

	str = ft_strdup(s);
	/*1*/check(ft_strlen(str) == ft_strlen(s));
	mcheck(str, (ft_strlen(s) + 1) * sizeof(char));
	/*2*/check(!strcmp(s, str));
	free(str);
	str = ft_strdup("");
	/*3*/check(str[0] == 0);
	free(str);
	printf("\n");
}
