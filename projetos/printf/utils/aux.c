/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:33:27 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 18:53:44 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_char(int nbr, char c)
{
	while (nbr > 0)
	{
		write(1, &c, 1);
		nbr--;
	}
}

void	print_hexa(long int nbr)
{
	char	*hexa;
	int		digit;

	digit = nbr % 16;
	hexa = "0123456789abcdef";
	if (nbr)
	{
		print_hexa(nbr / 16);
		write(1, &hexa[digit], 1);
	}
}

int		get_hexalen(long int nbr)
{
	char	*hexa;
	int		size;

	size = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		size++;
	}
	return (size);
}
