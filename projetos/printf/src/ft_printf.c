/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:38 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 17:41:36 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *string, ...)
{
	t_param	param;

	set_param_struct(&param);
	va_start(param.ptr, string);
	while (*string)
	{
		if (*string == '%')
		{
			if (verify_format(string + 1, &param))
			{
				string = store_info(&param, string + 1);
				print_param(&param, *string);
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

void	set_param_struct(t_param *param)
{
	ft_bzero(param, sizeof(t_param));
	param->flags = "-+0 #";
	param->convert = "diuscpx";
}