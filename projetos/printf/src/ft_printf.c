/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:38 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 10:26:26 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *string, ...)
{
	t_expression	expression;

	set_expression_struct(&expression);
	va_start(expression.ptr, string);
	while (*string)
	{
		if (*string == '%')
		{
			if (verify_format(string + 1, &expression))
			{
				string = store_info(&expression, string + 1);
				print_param(&expression, *string);
				ft_bzero(&expression.assets, sizeof(expression.assets));
			}
			else
				write(1, string, 1);
		}
		else
			write(1, string, 1);
		string++;
	}
	va_end(expression.ptr);
	return (0);
}

void	set_expression_struct(t_expression *expression)
{
	ft_bzero(expression, sizeof(t_expression));
	expression->flags = "-+0 #";
	expression->types = "diuscpx";
}