/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:38 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 09:56:13 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *string, ...)
{
	t_param	param;
	va_list	ptr;
	int		offset;

	va_start(ptr, string);
	param.flags = "-+0 #";
	param.convert = "diuscpx";
	while (*string)
	{
		if (*string == '%')
		{
			offset = verify_format(string + 1, param);
			if (offset)
			{
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
	return (0);
}
