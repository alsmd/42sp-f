/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:11:36 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 09:25:57 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void print_info(t_expression *expression)
{
	printf("width: %d\n", expression->assets.width);
	printf("left_space: %d\n", expression->assets.left_space);
	printf("right_space: %d\n", expression->assets.right_space);
	printf("left_zero: %d\n", expression->assets.left_zero);
	printf("dotte_nbr: %d\n", expression->assets.dotte_nbr);
	printf("type: %d\n", expression->assets.type);
}

static char	*store_flags(t_expression *expression, char *string)
{
	while (ft_strchr(expression->flags, *string))
	{
		if (*string == '-')
		{
			expression->assets.left_space = 0;
			expression->assets.left_zero = 0;
			expression->assets.right_space = 1;
		}
		if (*string == '0')
		{
			if (!(expression->assets.right_space))
			{
				expression->assets.left_zero = 1;
				expression->assets.left_space = 0;
			}
		}
		if (*string == '+')
			expression->assets.plus_sinal = 1;
		if (*string == '#')
			expression->assets.prefix = 1;
		if (*string == ' ')
			expression->assets.space_flag = 1;
		string++;
	}
	return (string);
}

static char	*store_width(t_expression *expression, char *string)
{
	while (ft_isdigit(*string))
	{
		expression->assets.width = (expression->assets.width * 10) + (*string - 48);
		string++;
	}
	return (string);
}

static char	*store_dotte(t_expression *expression, char *string)
{
	int	n;
	
	if (*string == '.')
	{
		string++;
		while (ft_isdigit(*string))
		{
			n = expression->assets.dotte_nbr;
			expression->assets.dotte_nbr = (n * 10) + (*string - 48);
			if (expression->assets.left_zero == 1)
			{
				expression->assets.left_zero = 0;
				expression->assets.left_space = 1;
			}
			string++;
		}
	}
	return (string);
}

char	*store_info(t_expression *expression, const char *string)
{
	expression->assets.left_space = 1;
	string = store_flags(expression, (char *)string);
	string = store_width(expression, (char *)string);
	string = store_dotte(expression, (char *)string);
	expression->assets.type = *string;
	return ((char *)string);
}