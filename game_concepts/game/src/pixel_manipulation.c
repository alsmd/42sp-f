/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 16:28:58 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	my_mlx_get_pixel(t_data *data, int x, int y)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dest);
}

void	copy_img(t_data *dest, t_data *src, int x_src, int y_src, int width, int height)
{
	int	pixel;
	int	x;
	int	y;
	int	holder;

	x = 0;
	y = 0;
	holder = y_src;
	while (x < width)
	{
		while (y < height)
		{
			pixel = my_mlx_get_pixel(src, x_src, y_src);
			my_mlx_pixel_put(dest, x, y, pixel);
			y++;
			y_src++;
		}
		y = 0;
		y_src = holder;
		x_src++;
		x++;
	}
}