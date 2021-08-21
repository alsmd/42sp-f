/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 07:59:33 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	desabilite_flags(t_assets *assets)
{
	assets->hash_flag = 0;
}

void	print_d(t_assets *assets)
{
	size_t	size;
	char	*buffer;
	int		number;

	number = va_arg(assets->ptr, int);
	desabilite_flags(assets);
	if (number < 0)
	{
		buffer = ft_itoa(number * -1);
		assets->is_negative = 1;
		assets->space_flag = 0;
		assets->plus_flag = 0;
	}
	else
		buffer = ft_itoa(number);
	assets->wrote += ft_strlen(buffer);
	set_sizes(assets, buffer, number);
	if (assets->space_flag && !assets->plus_flag)
	{
		write(1, " ", 1);
		assets->wrote += 1;
	}
	print_left(assets, 1);
	print_sign(assets);
	print_left(assets, 0);
	print_precision(assets);
	ft_putstr_fd(buffer, 1);
	print_right(assets);
	free(buffer);
}
