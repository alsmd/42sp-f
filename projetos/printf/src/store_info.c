/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:11:36 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 09:21:19 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void print_info(t_param *param)
{
	printf("width: %d\n", param->assets.width);
	printf("left_space: %d\n", param->assets.left_space);
	printf("right_space: %d\n", param->assets.right_space);
	printf("left_zero: %d\n", param->assets.left_zero);
	printf("dotte_nbr: %d\n", param->assets.dotte_nbr);
}

static char	*store_flags(t_param *param, char *string)
{
	while (ft_strchr(param->flags, *string))
	{
		if (*string == '-')
		{
			param->assets.left_space = 0;
			param->assets.left_zero = 0;
			param->assets.right_space = 1;
		}
		if (*string == '0')
		{
			if (!(param->assets.right_space))
			{
				param->assets.left_zero = 1;
				param->assets.left_space = 0;
			}
		}
		if (*string == '+')
			param->assets.plus_sinal = 1;
		if (*string == '#')
			param->assets.prefix = 1;
		if (*string == ' ')
			param->assets.space_flag = 1;
		string++;
	}
	return (string);
}

static char	*store_width(t_param *param, char *string)
{
	while (ft_isdigit(*string))
	{
		param->assets.width = (param->assets.width * 10) + (*string - 48);
		string++;
	}
	return (string);
}

static char	*store_dotte(t_param *param, char *string)
{
	int	n;
	
	if (*string == '.')
	{
		string++;
		while (ft_isdigit(*string))
		{
			n = param->assets.dotte_nbr;
			param->assets.dotte_nbr = (n * 10) + (*string - 48);
			if (param->assets.left_zero == 1)
			{
				param->assets.left_zero = 0;
				param->assets.left_space = 1;
			}
			string++;
		}
	}
	return (string);
}

char	*store_info(t_param *param, const char *string)
{
	param->assets.left_space = 1;
	string = store_flags(param, (char *)string);
	string = store_width(param, (char *)string);
	string = store_dotte(param, (char *)string);
	return ((char *)string);
}