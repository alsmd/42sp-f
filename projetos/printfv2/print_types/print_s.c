/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 07:35:05 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	desabilite_flags(t_assets *assets)
{
	assets->space_flag = 0;
	assets->plus_flag = 0;
	assets->hash_flag = 0;
	assets->zero_flag = 0;
	assets->precision = 0;
	assets->size = 0;
}

void	print_s(t_assets *assets)
{
	char	*buffer;
	char	*holder;

	holder = va_arg(assets->ptr, char *);
	if (holder == 0)
	{
		if (assets->precision)
			buffer = ft_strdup("");
		else
			buffer = ft_strdup("(null)");
	}
	else
	{
		buffer = ft_strdup(holder);
		if (assets->precision && assets->size < ft_strlen(buffer))
			buffer[assets->size] = '\0';
	}
	assets->wrote += ft_strlen(buffer);
	desabilite_flags(assets);
	set_sizes(assets, buffer, 0);
	print_left(assets, 1);
	print_left(assets, 0);
	ft_putstr_fd(buffer, 1);
	print_right(assets);
	free(buffer);
}
