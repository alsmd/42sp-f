/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:29:22 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 09:47:02 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	conversion_c(t_param *param)
{
	
}
void	conversion_s(t_param *param)
{
	param->buffer = va_arg(param->ptr, char *);
	param->assets.width -= ft_strlen(param->buffer);
	if (param->assets.left_space || param->assets.left_zero)
		print_char(param->assets.width, ' ');
	ft_putstr_fd(param->buffer, 1);
	if (param->assets.right_space)
		print_char(param->assets.width, ' ');
}

void	conversion_p(t_param *param)
{
	
}

void	conversion_d(t_param *param)
{
	int	number;
	
	number = va_arg(param->ptr, int);
	param->buffer = ft_itoa(number);
	param->assets.width -= ft_strlen(param->buffer);
	param->assets.dotte_nbr -= ft_strlen(param->buffer);
	if (number > 0 &&  param->assets.plus_sinal)
		param->assets.width--;
	if (param->assets.dotte_nbr > 0)
		param->assets.width -= param->assets.dotte_nbr;
	if (param->assets.width <= 0 && !param->assets.plus_sinal)
	{
		if (param->assets.space_flag)
			write(1, " ", 1);
	}
	if (param->assets.left_space)
		print_char(param->assets.width, ' ');
	if (param->assets.left_zero)
		print_char(param->assets.width, '0');
	if (number > 0 && param->assets.plus_sinal)
		write(1, "+", 1);
	while (param->assets.dotte_nbr-- > 0)
		write(1, "0", 1);
	ft_putstr_fd(param->buffer, 1);
	if (param->assets.right_space)
		print_char(param->assets.width, ' ');

}

void	conversion_i(t_param *param)
{
	
}
