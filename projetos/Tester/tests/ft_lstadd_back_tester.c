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

void	ft_lstadd_back_tester()
{
	title("ft_lstadd_back");

	t_list	*begin;
	begin = 0;
	ft_lstadd_back(&begin, ft_lstnew("1"));
	/*1*/check(!strcmp(begin->content, "1"));
	ft_lstadd_back(&begin, ft_lstnew("2"));
	/*3*/check(!strcmp(begin->next->content, "2"));
	ft_lstadd_back(&begin, ft_lstnew("3"));
	/*4*/check(!strcmp(begin->next->next->content, "3"));
	ft_lstadd_back(&begin, ft_lstnew("4"));
	/*5*/check(!strcmp(begin->next->next->next->content, "4"));
	free_list(begin);
	printf("\n");
}
