/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:35:37 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 10:05:55 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	check_sign(int number, t_assets assets)
{
	if (assets.type != 'u')
	{
		if (number > 0 && assets.plus_sinal)
		write(1, "+", 1);
		if (number < 0)
			write(1, "-", 1);
	}
}
static void	print_formated_content(t_expression *expression, int number)
{
	if (expression->assets.left_space)
		print_char(expression->assets.width, ' ');
	if (expression->assets.left_zero)
		print_char(expression->assets.width, '0');
	check_sign(number, expression->assets);
	while (expression->assets.dotte_nbr-- > 0)
		write(1, "0", 1);
	ft_putstr_fd(expression->buffer, 1);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
}

void	type_d_i(t_expression *expression)
{
	int	number;
	
	number = va_arg(expression->ptr, int);
	expression->buffer = ft_itoa(number);
	if (number < 0)
		expression->buffer++;
	expression->assets.width -= ft_strlen(expression->buffer);
	expression->assets.dotte_nbr -= ft_strlen(expression->buffer);
	if (number > 0 && expression->assets.plus_sinal)
		expression->assets.width--;
	if (expression->assets.dotte_nbr > 0)
		expression->assets.width -= expression->assets.dotte_nbr;
	if (expression->assets.width <= 0 && !expression->assets.plus_sinal)
	{
		if (expression->assets.space_flag)
			write(1, " ", 1);
	}
	print_formated_content(expression, number);
}

void	type_u(t_expression *expression)
{
	unsigned	number;
	
	number = va_arg(expression->ptr, int);
	expression->buffer = ft_itoa(number);
	expression->assets.width -= ft_strlen(expression->buffer);
	expression->assets.dotte_nbr -= ft_strlen(expression->buffer);
	if (expression->assets.dotte_nbr > 0)
		expression->assets.width -= expression->assets.dotte_nbr;
	if (expression->assets.width <= 0)
	{
		if (expression->assets.space_flag)
			write(1, " ", 1);
	}
	print_formated_content(expression, 0);
}