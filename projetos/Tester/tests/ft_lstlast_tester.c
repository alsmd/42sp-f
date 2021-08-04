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

void	ft_lstlast_tester()
{
	title("ft_lstlast");

	t_list	*begin;
	t_list	*last;
	begin = 0;
	/*0*/check(ft_lstlast(begin) == begin);
	ft_lstadd_front(&begin, ft_lstnew("1"));
	/*1*/check(ft_lstlast(begin) == begin);
	ft_lstadd_front(&begin, ft_lstnew("2"));
	ft_lstadd_front(&begin, ft_lstnew("3"));
	ft_lstadd_front(&begin, ft_lstnew("4"));
	ft_lstadd_front(&begin, ft_lstnew("5"));
	ft_lstadd_front(&begin, ft_lstnew("6"));
	ft_lstadd_front(&begin, ft_lstnew("7"));
	last = ft_lstlast(begin);
	/*2*/check(!strcmp(last->content, "1"));
	/*3*/check((ft_lstlast(begin))->next == 0);
	free_list(begin);
	printf("\n");
}
