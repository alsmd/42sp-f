/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 13:45:19 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>////////////////////////////
typedef short int	boolean;

typedef struct s_param
{
	char	*flags;
	char	*convert;
	char	*buffer;
	va_list	ptr;
	boolean	left_space;
	boolean	right_space;
	boolean	left_zero;
	int		width;
	int		dotte_nbr;
	boolean	octal_prefix;
	boolean	hexa_prefix;
}	t_param;

//*****Main******//
int	ft_printf(const char *string, ...);

/*
	@param string	The first character of the expression (ex: '-' in '%-10d')
	@param param	Will be a struct that contains informations about how the
					expression should be format
	@brief			The function will check if the given expression is formatted
					correctly.
	@return			Return the number of characters present into the expression.
					or 0 if the expression is bad formated.('%' does not count);

*/
int		verify_format(const char *string, t_param *param);

/*
	@param param	Will be a struct that contains informations about how the
					expression should be format
	@param string	The first character of the expression (ex: '-' in '%-10d')
	@brief			Will get informations about the expression, like:
					if there will be zero or space to complete the min-width,
					or if there will be a min-width, and informations about
					other flags.
*/
void	store_info(t_param *param, const char *string);

#endif