/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 08:33:55 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	desabilite_flags(t_assets *assets)
{
	assets->space_flag = 0;
	assets->plus_flag = 0;
}

void	print_x(t_assets *assets)
{
	char	*buffer;
	t_hexa	number;

	number = va_arg(assets->ptr, unsigned int);
	if (number == 0)
		buffer = ft_strdup("0");
	else
		buffer = hexa_to_string(number, assets);
	assets->wrote += ft_strlen(buffer);
	desabilite_flags(assets);
	set_sizes(assets, buffer, number);
	if (!assets->zero_flag || assets->precision)
		print_left(assets);
	if (assets->hash_flag && number != 0)
	{
		write(1, "0x", 2);
		assets->wrote += 2;
	}
	if (assets->zero_flag && !assets->precision)
		print_left(assets);
	print_precision(assets);
	ft_putstr_fd(buffer, 1);
	print_right(assets);
	free(buffer);
}
