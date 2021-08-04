#include "../test.h"

void	ft_strtrim_tester()
{
	title("ft_strtrim");
	char	*s = strdup("----   uma - string - a - ser - truncada    ---");
	char	*string;

	string = ft_strtrim(s, " -");
	/*1*/check(!strcmp(string, "uma - string - a - ser - truncada"));
	/*2*/mcheck(string, (strlen("uma - string - a - ser - truncada") + 1) * sizeof(char));
	free(s);
	free(string);
	string = ft_strtrim("", " -");
	/*3*/check(!strcmp(string, ""));
	/*4*/mcheck(string, 1 * sizeof(char));
	free(string);
	string = ft_strtrim("- - - - - -   ---  --  -- - - -", " -");
	/*5*/check(!strcmp(string, ""));
	/*6*/mcheck(string, 1 * sizeof(char));
	free(string);
	printf("\n");
}
