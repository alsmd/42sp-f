/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:16:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 20:43:41 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	creat_ash_images(t_ash *ash, t_vars *vars)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		ash->front[x].img = mlx_new_image(vars->mlx, 68, 72);
		ash->front[x].addr = mlx_get_data_addr(ash->front[x].img, &ash->front[x].bits_per_pixel, &ash->front[x].line_length, &ash->front[x].endin);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		ash->left[x].img = mlx_new_image(vars->mlx, 68, 72);
		ash->left[x].addr = mlx_get_data_addr(ash->left[x].img, &ash->left[x].bits_per_pixel, &ash->left[x].line_length, &ash->left[x].endin);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		ash->right[x].img = mlx_new_image(vars->mlx, 68, 72);
		ash->right[x].addr = mlx_get_data_addr(ash->right[x].img, &ash->right[x].bits_per_pixel, &ash->right[x].line_length, &ash->right[x].endin);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		ash->back[x].img = mlx_new_image(vars->mlx, 68, 72);
		ash->back[x].addr = mlx_get_data_addr(ash->back[x].img, &ash->back[x].bits_per_pixel, &ash->back[x].line_length, &ash->back[x].endin);
		x++;
	}
}

void	copy_ash_images(t_ash *ash, t_data *img)
{
	int		h;
	int		x;
	int		w;

	h = 72;
	w = 68;
	x = 0;
	while (x < 4)
	{
		copy_img(&ash->front[x], img, x * w, h * 0, 68, 72);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		copy_img(&ash->left[x], img, x * w, h * 1, 68, 72);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		copy_img(&ash->right[x], img, x * w, h * 2, 68, 72);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		copy_img(&ash->back[x], img, x * w, h * 3, 68, 72);
		x++;
	}
}
void	get_ash(t_ash *ash, t_vars *vars)
{
	t_data	img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./imgs/ash.xpm";
	img_width = 272;
	img_height = 288;
	img.img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	creat_ash_images(ash, vars);
	copy_ash_images(ash, &img);
}