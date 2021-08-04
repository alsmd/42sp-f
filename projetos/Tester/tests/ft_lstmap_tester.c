#include "../test.h"

static void	*to_uppercase(void	*data)
{
	char	*s;
	char	*cpy;
	int		index;

	index = 0;
	s = data;
	cpy = (char *) ft_calloc(strlen(s) + 1, sizeof(char));
	while (*s)
	{
		if (*s >= 95 && *s <= 122)
			cpy[index] = *s - 32;
		else
			cpy[index] = *s;
		s++;
		index++;
	}
	return (cpy);
}

void	ft_lstmap_tester()
{
	title("ft_lstmap");
	t_list	*begin;
	t_list	*cpy;

	begin = 0;
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	cpy = ft_lstmap(begin, to_uppercase, free);
	/*1*/check(!strcmp(cpy->content, "ABCD"));
	/*2*/check(!strcmp(cpy->next->content, "ABCD"));
	/*3*/check(!strcmp(cpy->next->next->content, "ABCD"));
	/*4*/check(!strcmp(cpy->next->next->next->content, "ABCD"));
	ft_lstclear(&cpy, free);
	ft_lstclear(&begin, free);
	printf("\n");
}
