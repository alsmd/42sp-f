/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:16:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 10:07:52 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"



void	print_param(t_expression *expression, char type)
{
	int	n;

	if (type == 's' || type == 'c')
		type_s_c(expression);	
	if (type == 'd' || type == 'i')
		type_d_i(expression);
	if (type == 'u')
		type_u(expression);
	if (type == '%')
		type_percent(expression);
	if (type == 'p')
		type_p(expression);
	if (type == 'x')
		type_x(expression);
}