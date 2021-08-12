/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/12 09:17:14 by flavio           ###   ########.fr       */
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

/*
	@brief Assets will be the informations about what the given parameter will contain.
			If there will be spaces before or after the content, or if 0's is necessary.
			If there will be a prefix like '0x' or '0', and similar things.
*/
typedef struct s_assets
{
	boolean	left_space;
	boolean	right_space;
	boolean	left_zero;
	boolean	plus_sinal;
	boolean	space_flag;
	int		dotte_nbr;
	int		width;
	boolean	prefix;
}	t_assets;
typedef struct s_param
{
	char		*flags;
	char		*convert;
	char		*buffer;
	t_assets	assets;
	va_list	ptr;
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
	@return			returns the adress of the convertions letter (ex: s,c,i,d)
*/
char	*store_info(t_param *param, const char *string);

void	print_param(t_param *param, char type);
void	set_param_struct(t_param *param);

//*****Utils******//
/*
	@brief		all the conversion functions will print
				the given parameter on the screen using 
				informations about how it should be formated.
				For exemple the 's' ignores the precision point
				and '0' flag, and just is formated by '-' and width.
*/
void	conversion_c(t_param *param);
void	conversion_s(t_param *param);
void	conversion_p(t_param *param);
void	conversion_d(t_param *param);
void	conversion_i(t_param *param);
void	conversion_x(t_param *param);
void	conversion_percent(t_param *param);
void	print_char(int nbr, char c);

#endif