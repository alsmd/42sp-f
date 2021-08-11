/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:11:36 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 13:45:08 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void print_info(t_param *param)
{
	printf("width: %d\n", param->width);
	printf("left_space: %d\n", param->left_space);
	printf("right_space: %d\n", param->right_space);
	printf("left_zero: %d\n", param->left_zero);
	printf("dotte_nbr: %d\n", param->dotte_nbr);
}

static char	*store_flags(t_param *param, char *string)
{
	while (ft_strchr(param->flags, *string))
	{
		if (*string == '-')
		{
			param->left_space = 0;
			param->left_zero = 0;
			param->right_space = 1;
		}
		if (*string == '0')
		{
			if (!(param->right_space))
			{
				param->left_zero = 1;
				param->left_space = 0;
			}
		}
		string++;
	}
	return (string);
}

static char	*store_width(t_param *param, char *string)
{
	while (ft_isdigit(*string))
	{
		param->width = (param->width * 10) + (*string - 48);
		string++;
	}
	return (string);
}

static char	*store_dotte(t_param *param, char *string)
{
	if (*string == '.')
	{
		string++;
		while (ft_isdigit(*string))
		{
			param->dotte_nbr = (param->dotte_nbr * 10) + (*string - 48);
			string++;
		}
	}
	return (string);
}

void	store_info(t_param *param, const char *string)
{
	param->left_space = 1;
	string = store_flags(param, (char *)string);
	string = store_width(param, (char *)string);
	store_dotte(param, (char *)string);
	print_info(param);
}