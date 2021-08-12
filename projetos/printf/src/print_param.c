/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:16:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 15:31:52 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"



void	print_param(t_expression *expression, char type)
{
	int	n;

	if (type == 's')
		conversion_s(expression);	
	if (type == 'd')
		conversion_d(expression);
	if (type == 'c')
		conversion_c(expression);
	if (type == 'i')
		conversion_i(expression);
	if (type == 'u')
		conversion_u(expression);
	if (type == '%')
		conversion_percent(expression);
	if (type == 'p')
		conversion_p(expression);
	if (type == 'x')
		conversion_x(expression);
}