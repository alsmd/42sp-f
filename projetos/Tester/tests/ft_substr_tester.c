#include "../test.h"

void	ft_substr_tester()
{
	title("ft_substr");
	char	*str = "Isso é uma bela de uma fabulosa de uma string";
	char	*sub;

	sub = ft_substr(str, 0, 10);
	/*1*/check(!strncmp(str, sub, 10));
	/*2*/mcheck(sub, 11 * sizeof(char));
	free(sub);
	sub = ft_substr(str, 0, 10000);
	/*3*/check(!strcmp(str, sub));
	/*4*/mcheck(sub, (strlen(str) + 1) * sizeof(char));
	free(sub);
	sub = ft_substr(str, 1000, 10);
	/*3*/check(!strcmp(sub, ""));
	/*4*/mcheck(sub, 1 * sizeof(char));
	free(sub);
	printf("\n");
}
