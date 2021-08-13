/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:34:25 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 10:06:11 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	type_s_c(t_expression *expression)
{
	if (expression->assets.type == 's')
		expression->buffer = ft_strdup(va_arg(expression->ptr, char *));
	else
		expression->buffer = char_to_string(va_arg(expression->ptr, int));
	expression->assets.width -= ft_strlen(expression->buffer);
	if (expression->assets.left_space || expression->assets.left_zero)
		print_char(expression->assets.width, ' ');
	ft_putstr_fd(expression->buffer, 1);
	if (expression->assets.right_space)
		print_char(expression->assets.width, ' ');
	free(expression->buffer);
}
