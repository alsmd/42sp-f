#include "../test.h"

void	ft_lstclear_tester()
{
	title("ft_lstclear");

	t_list	*begin;

	begin = ft_lstnew(strdup("1"));
	ft_lstadd_back(&begin, ft_lstnew(strdup("2")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("3")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("4")));
	ft_lstadd_back(&begin, ft_lstnew(strdup("5")));
	ft_lstclear(&begin, free);
	///*1*/check(!begin);
	printf("\n");
}
