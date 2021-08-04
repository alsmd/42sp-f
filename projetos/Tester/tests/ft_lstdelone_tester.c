#include "../test.h"

void	ft_lstdelone_tester()
{
	title("ft_lstdelone");

	t_list	*begin;
	t_list	*element;
	char	*content = strdup("yo sup");

	element = ft_lstnew("SHOW");
	begin = ft_lstnew(content);

	ft_lstadd_back(&begin, element);
	ft_lstdelone(begin, free);
	///*1*/check(element != 0);
	///*2*/check(!malloc_usable_size(content));
	free(element);
	printf("\n");
}
