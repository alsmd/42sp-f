/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 16:20:52 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	set_sizes(t_assets *assets, char *buffer, int number)
{
	if (assets->size > 0)
	{
		if (buffer[0] == '-')
			assets->size -= ft_strlen(buffer + 1);
		else
			assets->size -= ft_strlen(buffer);
	}
	if (assets->width > 0)
	{
		assets->width -= (ft_strlen(buffer));
		if (assets->size > 0)
			assets->width -= assets->size;
		if (assets->plus_flag || assets->space_flag)
			assets->width -= 1;
		if (number < 0)
			assets->width -= 1;
	}
}

void	print_d(t_assets *assets)
{
	size_t	size;
	char	*buffer;
	int		number;

	number = va_arg(assets->ptr, int);
	if (number < 0)
		buffer = ft_itoa(number * -1);
	else
		buffer = ft_itoa(number);
	set_sizes(assets, buffer, number);
	printf("width :%d\n", assets->width);
	printf("size :%d\n", assets->size);
}
