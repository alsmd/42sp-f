/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:38 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 13:15:53 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *string, ...)
{
	t_param	param;
	int		offset;

	ft_bzero(&param, sizeof(t_param));
	param.flags = "-+0 #";
	param.convert = "diuscpx";
	va_start(param.ptr, string);
	while (*string)
	{
		if (*string == '%')
		{
			offset = verify_format(string + 1, &param);
			if (offset)
			{
				store_info(&param, string + 1);
				//print the parameter with the right format
				string += offset;				
			}
			else
				write(1, string, 1);
		}
		else
			write(1, string, 1);
		string++;
	}
	va_end(param.ptr);
	return (0);
}
