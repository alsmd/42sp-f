#include "../test.h"

static void	to_uppercase(void	*data)
{
	char	*s;

	s = data;
	while (*s)
	{
		if (*s >= 95 && *s <= 122)
			*s -= 32;
		s++;
	}
}

void	ft_lstiter_tester()
{
	title("ft_lstiter");
	t_list	*begin;

	begin = 0;
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("abcd")));
	ft_lstiter(begin, to_uppercase);
	/*1*/check(!strcmp(begin->content, "ABCD"));
	/*2*/check(!strcmp(begin->next->content, "ABCD"));
	/*3*/check(!strcmp(begin->next->next->content, "ABCD"));
	/*4*/check(!strcmp(begin->next->next->next->content, "ABCD"));
	ft_lstclear(&begin, free);
	printf("\n");
}
