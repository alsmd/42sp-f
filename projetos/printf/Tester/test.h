/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:03:57 by flavio            #+#    #+#             */
/*   Updated: 2021/08/13 08:43:34 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>
#include "../ft_printf.h"
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
void	type_c();

#endif