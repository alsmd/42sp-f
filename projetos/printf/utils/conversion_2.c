/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:29:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 07:54:40 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	conversion_u(t_expression *expression)
{
	unsigned	number;
	
	number = va_arg(expression->ptr, int);
	expression->buffer = ft_itoa(number);
	expression->assets.width -= ft_strlen(expression->buffer);
	expression->assets.dotte_nbr -= ft_strlen(expression->buffer);
	if (expression->assets.dotte_nbr > 0)
		expression->assets.width -= expression->assets.dotte_nbr;
	if (expression->assets.width <= 0 && !expression->assets.plus_sinal)
	{
		if (expression->assets.space_flag)
			write(1, " ", 1);
	}
	if (expression->assets.left_space)
		print_char(expression->assets.width, ' ');
	if (expression->assets.left_zero)
		print_char(expression->assets.width, '0');
	while (expression->assets.dotte_nbr-- > 0)
		write(1, "0", 1);
	ft_putstr_fd(expression->buffer, 1);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
}

void	conversion_x(t_expression *expression)
{
	long int	number;

	number = va_arg(expression->ptr, int);
	expression->assets.width -= get_hexalen(number);
	expression->assets.dotte_nbr -= get_hexalen(number);
	if (expression->assets.dotte_nbr > 0)
		expression->assets.width -= expression->assets.dotte_nbr;
	if (expression->assets.prefix)
		expression->assets.width -= 2;
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

void	conversion_percent(t_expression *expression)
{
	write(1, "%", 1);
}