/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 06:01:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/11 09:26:55 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef short int	boolean;

typedef struct s_param
{
	char	*flags;
	char	*convert;
	boolean	left_space;
	boolean	right_space;
	boolean	left_zero;
	int		qnt_space;
	int		qnt_zero;
	boolean	octal_prefix;
	boolean	hexa_prefix;
}	t_param;

//*****Main******//
int	ft_printf(const char *string, ...);

int	verify_format(const char *string, t_param param);

#endif