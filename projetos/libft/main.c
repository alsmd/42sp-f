/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:59:02 by flavio            #+#    #+#             */
/*   Updated: 2021/08/03 10:05:44 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

int	main(void)
{
	int	i;

	i = -1;
	while (i < 530)
	{
		/* if (ft_isalnum(i) != isalnum(i))
		{
			printf("Fail: %d \n", i);
			printf("ft_isalnum:%d \n", ft_isalnum(i));
			printf("isalnum:%d \n", isalnum(i));
		} */
		printf("Num:%d \n", i);
		printf("isalnum:%d \n", isalnum(i));

		i++;
	}	

	return (0);
}
