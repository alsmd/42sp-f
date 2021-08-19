/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:55:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 21:48:14 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	reset_assets(t_assets *assets)
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
