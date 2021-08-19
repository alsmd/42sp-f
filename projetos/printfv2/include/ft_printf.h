/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 21:51:50 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "#- +0"
# define TYPES "cs%pdixu"
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
//tirar
# include <stdio.h>
//ate aqui
typedef short int	t_boolean;

/*
	@brief	WIll contain informations about the expression after %.
*/
typedef struct s_assets
{
	va_list		ptr;
	t_boolean	less_flag;
	t_boolean	zero_flag;
	t_boolean	plus_flag;
	t_boolean	space_flag;
	t_boolean	hash_flag;
	t_boolean	is_negative;
	t_boolean	precision;
	int			size;
	int			width;
	int			wrote;
	char		type;
}	t_assets;

/*
	@brief		Mimic printf with flags " +-#0", precision and types "cs%pdixu"
*/
int		ft_printf(const char *string, ...);

/*
	@param string		The first character of the expression (ex: '-' in '%-10d')
	@brief				The function will check if the given expression is formatted
						correctly.
	@return				returns 0 if the expression is bad formated or
						a positive int.
*/
int		verify_format(const char *string, t_assets *assets);

/*
	@param string	The first character of the expression(ex: '-' in '%-10d')
	@brief			Will store informations about actives flags, width
					and precision.
	@return			returns the adress of the type letter (ex: s,c,i,d)
*/
char	*store_info(t_assets *assets, const char *string);

//brief		Will redirect to corresponding print function of the chosen type.
void	print_controller(t_assets *assets);

//@brief	print an integer according to the flags, width and size.
void	print_d(t_assets *assets);

//@brief	print a character according to the flags, width and size.
void	print_c(t_assets *assets);

//@brief	print an unsigned int according to the flags, width and size.
void	print_u(t_assets *assets);

//@brief	Will set the width and size depending on flags and parameter's len
void	set_sizes(t_assets *assets, char *buffer, int number);

//@brief	Will print sign if the flags is active
void	print_sign(t_assets *assets);

//@brief	WIll print spaces or 0's based on width if the flags is active
void	print_left(t_assets *assets);

//@brief	Will print 0's based on size if the flag is active
void	print_precision(t_assets *assets);

//@brief	Will print spaces based on width if the flag is active
void	print_right(t_assets *assets);

//@brief	Will reset the informations about the expression.
void	reset_assets(t_assets *assets);
#endif