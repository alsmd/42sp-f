/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:03:05 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 19:25:15 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	type_x(t_expression *expression)
{
	long int	number;

	number = va_arg(expression->ptr, int);
	expression->assets.width -= get_hexalen(number);
	expression->assets.dotte_nbr -= get_hexalen(number);
	if (expression->assets.dotte_nbr > 0)
		expression->assets.width -= expression->assets.dotte_nbr;
	if (expression->assets.prefix)
	{
		expression->wrote += 2;
		expression->assets.width -= 2;
	}
	expression->wrote += get_hexalen(number);
	if (expression->assets.width > 0)
		expression->wrote += expression->assets.width;
	if (expression->assets.dotte_nbr > 0)
		expression->wrote += expression->assets.dotte_nbr;
	if (expression->assets.left_space)
		print_char(expression->assets.width, ' ');
	if (expression->assets.left_zero)
		print_char(expression->assets.width, '0');
	if (expression->assets.prefix)
		write(1, "0x", 2);
	while (expression->assets.dotte_nbr-- > 0)
		write(1, "0", 1);
	print_hexa(number);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
}

void	type_p(t_expression *expression)
{
	void		*ptr;
	long int	number;

	ptr = va_arg(expression->ptr, void *);
	number = (long int)ptr;
	expression->assets.width -= get_hexalen(number);
	expression->assets.width -= 2;
	expression->assets.dotte_nbr -= get_hexalen(number);
	if (number > 0 && expression->assets.plus_sinal)
		expression->assets.width--;
	if (expression->assets.dotte_nbr > 0)
		expression->assets.width -= expression->assets.dotte_nbr;
	expression->wrote += get_hexalen(number) + 2;
	if (expression->assets.width > 0)
		expression->wrote += expression->assets.width;
	if (expression->assets.dotte_nbr > 0)
		expression->wrote += expression->assets.dotte_nbr;
	if (expression->assets.width <= 0 && !expression->assets.plus_sinal)//se this carefully // i need to considere both, left and right
	{
		if (expression->assets.space_flag)
		{
			write(1, " ", 1);
			expression->wrote++;
		}
	}
	if (expression->assets.left_space)
		print_char(expression->assets.width, ' ');
	if (expression->assets.left_zero)
		print_char(expression->assets.width, '0');
	if (number > 0 && expression->assets.plus_sinal)
	{
		expression->wrote++;
		write(1, "+", 1);
	}
	write(1, "0x", 2);
	while (expression->assets.dotte_nbr-- > 0)
		write(1, "0", 1);
	print_hexa(number);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
}
