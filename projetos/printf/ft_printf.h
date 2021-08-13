/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 10:06:31 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>
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
	char	type;
	boolean	prefix;
}	t_assets;
typedef struct s_expression
{
	char		*flags;
	char		*types;
	char		*buffer;
	int			wrote;
	t_assets	assets;
	va_list	ptr;
}	t_expression;

//*****Main******//
int	ft_printf(const char *string, ...);

/*
	@param string		The first character of the expression (ex: '-' in '%-10d')
	@param expression	Will be a struct that contains informations about how the
						parameters should be format
	@brief				The function will check if the given expression is formatted
						correctly.
	@return				Return the number of characters present into the expression.
						or 0 if the expression is bad formated.('%' does not count);

*/
int		verify_format(const char *string, t_expression *expression);

/*
	@param expression	Will be a struct that contains informations about how the
						parameters should be format
	@param string		The first character of the expression (ex: '-' in '%-10d')
	@brief				Will get informations about the expression, like:
						if there will be zero or space to complete the min-width,
						or if there will be a min-width, and informations about
						other flags.
	@return				returns the adress of the convertions letter (ex: s,c,i,d)
*/
char	*store_info(t_expression *expression, const char *string);

void	print_param(t_expression *expression, char type);
void	set_expression_struct(t_expression *expression);

//*****Utils******//
/*
	@brief		all the conversion functions will print
				the given parameter on the screen using 
				informations about how it should be formated.
				For exemple the 's' ignores the precision point
				and '0' flag, and just is formated by '-' and width.
*/
void	type_s_c(t_expression *expression);
void	type_p(t_expression *expression);
void	type_d_i(t_expression *expression);
void	type_u(t_expression *expression);
void	type_x(t_expression *expression);
void	type_percent(t_expression *expression);


void	print_char(int nbr, char c);
void	print_hexa(long int nbr);
int		get_hexalen(long int nbr);
char	*char_to_string(int c);

#endif