/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:43:58 by flavio            #+#    #+#             */
/*   Updated: 2021/08/03 10:04:33 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	char	character;

	character = c;
	if (character >= 'a' && character <= 'z')
		return (8);
	if (character >= 'A' && character <= 'Z')
		return (8);
	if (character >= '0' && character <= '9')
		return (8);
	return (0);
}
