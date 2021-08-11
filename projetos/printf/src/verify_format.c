/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:04:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 12:29:37 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	verify_format(const char *string, t_param *param)
{
	int	mod;
	int	size;

	size = 0;
	mod = 0;
	while (ft_strchr(param->flags, string[size]))
		size++;
	while (ft_isdigit(string[size]))
		size++;
	if (string[size] == '.')
	{
		size++;
		while (ft_isdigit(string[size]))
			size++;
	}
	if ((ft_strchr(param->convert, string[size])))
		return (size + 1);
	return (0);
}