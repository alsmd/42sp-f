/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 15:53:27 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "#- +0"
# define TYPES "cs%pdix"
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>////////////////////////////

typedef short int	boolean;

/*
	@brief	WIll contain informations about the flags that was activeted.
			And how many characers was written in total
*/
typedef struct s_assets
{
	va_list	ptr;
	boolean	less_flag;
	boolean	zero_flag;
	boolean	plus_flag;
	boolean	space_flag;
	boolean	hash_flag;
	int		size;
	int		width;
	int		wrote;
	char	type;
}	t_assets;

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
int		verify_format(const char *string, t_assets *assets);

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
char	*store_info(t_assets *assets, const char *string);

/*
	@brief		Will redirect to corresponding type function
*/
void	print_controller(t_assets *assets);


/*print_type functions will print the parameter with the right format*/
/*depending on the flags, width and presition point*/
void	print_d(t_assets *assets);



//*****Utils******//
void	print_char(int nbr, char c);
void	print_hexa(long int nbr);
int		get_hexalen(long int nbr);
char	*char_to_string(int c);
char	*ft_itoa_un(unsigned int n);

#endif