#include "../test.h"

void	ft_lstnew_tester()
{
	title("ft_lstnew");
	t_list	*element;

	element = ft_lstnew("Salve minha gente");
	/*1*/check(!element->next);
	/*2*/check(!strcmp(element->content, "Salve minha gente"));
	/*3*/mcheck(element, sizeof(t_list) * 1);
	free(element);
	printf("\n");
}
