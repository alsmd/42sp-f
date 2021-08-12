/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:29:22 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 10:39:02 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	conversion_c(t_expression *expression)
{
	char	c =  va_arg(expression->ptr, int);
	
	expression->assets.width--;
	if (expression->assets.left_space || expression->assets.left_zero)
		print_char(expression->assets.width, ' ');
	write(1, &c, 1);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
}
void	conversion_s(t_expression *expression)
{
	expression->buffer = va_arg(expression->ptr, char *);
	expression->assets.width -= ft_strlen(expression->buffer);
	if (expression->assets.left_space || expression->assets.left_zero)
		print_char(expression->assets.width, ' ');
	ft_putstr_fd(expression->buffer, 1);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
}

void	conversion_p(t_expression *expression)
{
	
}

void	conversion_d(t_expression *expression)
{
	int	number;
	
	number = va_arg(expression->ptr, int);
	expression->buffer = ft_itoa(number);
	expression->assets.width -= ft_strlen(expression->buffer);
	expression->assets.dotte_nbr -= ft_strlen(expression->buffer);
	if (number > 0 &&  expression->assets.plus_sinal)
		expression->assets.width--;
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
	if (number > 0 && expression->assets.plus_sinal)
		write(1, "+", 1);
	while (expression->assets.dotte_nbr-- > 0)
		write(1, "0", 1);
	ft_putstr_fd(expression->buffer, 1);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');

}

void	conversion_i(t_expression *expression)
{
	
}
