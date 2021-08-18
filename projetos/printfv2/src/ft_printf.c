/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:41:12 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 15:53:40 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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