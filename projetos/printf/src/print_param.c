/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:16:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 08:07:39 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"



void	print_param(t_param *param, char type)
{
	int	n;

	if (type == 's')
		conversion_s(param);	
	if (type == 'd')
		conversion_d(param);	
}