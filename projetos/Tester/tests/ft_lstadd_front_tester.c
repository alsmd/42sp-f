#include "../test.h"

static void	free_list(t_list *begin)
{
	t_list	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

void	ft_lstadd_front_tester()
{
	title("ft_lstadd_front");
	t_list	*begin;

	begin = ft_lstnew("sup");
	ft_lstadd_front(&begin, ft_lstnew("now i'm the first one"));
	/*1*/check(!strcmp(begin->content, "now i'm the first one"));
	/*2*/check(!strcmp(begin->next->content, "sup"));
	/*3*/check(!begin->next->next);
	free_list(begin);
	begin = 0;
	ft_lstadd_front(&begin, ft_lstnew("hello"));
	/*4*/check(!strcmp(begin->content, "hello"));
	/*5*/check(!begin->next);
	free_list(begin);
	printf("\n");
}
