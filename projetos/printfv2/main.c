/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:52:12 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 09:23:30 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	redirect(char *name)
{
	close(1);
	open(name, O_WRONLY);
}

int	main(void)
{
	int	number;
	int	numbe2;


	ft_printf("|%p%## +30p|\n", &number, 0);
	printf("|%p%## +30p|\n", &number, 0);
	return (0);
}//                      (nil)
// 07FFFFFFF 080000000 00FFFFFFFF 000000000000 0000FFFFFFFF 00000000000000 000000FFFFFFD6