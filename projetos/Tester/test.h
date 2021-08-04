/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:03:57 by flavio            #+#    #+#             */
/*   Updated: 2021/08/03 05:56:31 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>
#include "../libft.h"
#include <malloc.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*-------Cores-------*/
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYN "\e[0;36m"
#define WHITE "\e[0;37m"
//utils
void	check(short int codition);
void	title(char	*string);
void	mcheck(void	*ptr, size_t size);
//test
void	ft_isalpha_tester();
void	ft_isdigit_tester();
void	ft_isalnum_tester();
void	ft_isascii_tester();
void	ft_isprint_tester();
void	ft_toupper_tester();
void	ft_tolower_tester();
void	ft_memset_tester();
void	ft_bzero_tester();
void	ft_memcpy_tester();
void	ft_memmove_tester();
void	ft_memchr_tester();
void	ft_memcmp_tester();
void	ft_calloc_tester();
void	ft_strlen_tester();
void	ft_strlcpy_tester();
void	ft_strlcat_tester();
void	ft_strchr_tester();
void	ft_strrchr_tester();
void	ft_strncmp_tester();
void	ft_strnstr_tester();
void	ft_atoi_tester();
void	ft_strdup_tester();
void	ft_substr_tester();
void	ft_strjoin_tester();
void	ft_strtrim_tester();
void	ft_split_tester();
void	ft_itoa_tester();
void	ft_strmapi_tester();
void	ft_striteri_tester();
void	ft_putchar_fd_tester();
void	ft_putstr_fd_tester();
void	ft_putendl_fd_tester();
void	ft_putnbr_fd_tester();
void	ft_lstnew_tester();
void	ft_lstadd_front_tester();
void	ft_lstsize_tester();
void	ft_lstlast_tester();
void	ft_lstadd_back_tester();
void	ft_lstdelone_tester();
void	ft_lstclear_tester();
void	ft_lstiter_tester();
void	ft_lstmap_tester();
#endif