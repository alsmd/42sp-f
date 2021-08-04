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

void	ft_lstsize_tester()
{
	title("ft_lstsize");
	
	t_list	*begin;
	begin = 0;
	/*1*/check(!ft_lstsize(begin));
	ft_lstadd_front(&begin, ft_lstnew("1"));
	/*2*/check(ft_lstsize(begin) == 1);
	ft_lstadd_front(&begin, ft_lstnew("2"));
	/*2*/check(ft_lstsize(begin) == 2);
	ft_lstadd_front(&begin, ft_lstnew("3"));
	/*3*/check(ft_lstsize(begin) == 3);
	ft_lstadd_front(&begin, ft_lstnew("4"));
	ft_lstadd_front(&begin, ft_lstnew("5"));
	ft_lstadd_front(&begin, ft_lstnew("6"));
	ft_lstadd_front(&begin, ft_lstnew("7"));
	/*4*/check(ft_lstsize(begin) == 7);
	free_list(begin);
	printf("\n");
}