/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 21:49:35 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	desabilite_flags(t_assets *assets)
{
	assets->space_flag = 0;
	assets->plus_flag = 0;
	assets->hash_flag = 0;
}

void	print_u(t_assets *assets)
{
	char			*buffer;
	unsigned int	number;

	number = va_arg(assets->ptr, unsigned int);
	buffer = ft_itoa(number);
	assets->wrote += ft_strlen(buffer);
	set_sizes(assets, buffer, number);
	print_left(assets);
	print_precision(assets);
	ft_putstr_fd(buffer, 1);
	print_right(assets);
	free(buffer);
}
