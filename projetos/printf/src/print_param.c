/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:16:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 10:32:22 by flavio           ###   ########.fr       */
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
}