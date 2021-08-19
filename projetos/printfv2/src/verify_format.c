/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:20:23 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 21:48:04 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	verify_format(const char *string, t_assets *assets)
{
	int	mod;
	int	size;

	size = 0;
	mod = 0;
	while (ft_strchr(FLAGS, string[size]))
		size++;
	while (ft_isdigit(string[size]))
		size++;
	if (string[size] == '.')
	{
		size++;
		while (ft_isdigit(string[size]))
			size++;
	}
	if ((ft_strchr(TYPES, string[size])))
		return (size + 1);
	return (0);
}
