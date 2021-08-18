/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:41:12 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 20:04:03 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	reset_assets(t_assets *assets)
{
	assets->less_flag = 0;
	assets->zero_flag = 0;
	assets->plus_flag = 0;
	assets->space_flag = 0;
	assets->hash_flag = 0;
	assets->is_negative = 0;
	assets->precision = 0;
	assets->size = 0;
	assets->width = 0;
	assets->type = 0;
}

int	ft_printf(const char *string, ...)
{
	t_assets	assets;

	ft_bzero(&assets, sizeof(assets));
	va_start(assets.ptr, string);
	while (*string)
	{
		if (*string == '%' && verify_format(string + 1, &assets))
		{
			string = store_info(&assets, string + 1);
			print_controller(&assets);
			reset_assets(&assets);
		}
		else
		{
			write(1, string, 1);
			assets.wrote += 1;
		}
		string++;
	}
	va_end(assets.ptr);
	return (assets.wrote);
}
