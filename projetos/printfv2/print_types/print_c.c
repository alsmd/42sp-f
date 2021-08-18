/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:09:15 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 20:27:21 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	desabilite_flags(t_assets *assets)
{
	assets->precision = 0;
	assets->space_flag = 0;
	assets->zero_flag = 0;
	assets->plus_flag = 0;
}

void	print_c(t_assets *assets)
{
	char	c;

	c = va_arg(assets->ptr, int);

	assets->wrote += 1;
	desabilite_flags(assets);
	set_sizes(assets, " ", 0);
	print_left(assets);
	write(1, &c, 1);
	print_right(assets);
}