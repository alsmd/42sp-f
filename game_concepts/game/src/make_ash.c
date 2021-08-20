/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:16:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 17:19:35 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	creat_ash_images(t_ash *ash, t_vars *vars)
{
	ash->front.img = mlx_new_image(vars->mlx, 68, 72);
	ash->front.addr = mlx_get_data_addr(ash->front.img, &ash->front.bits_per_pixel, &ash->front.line_length, &ash->front.endin);

	ash->left.img = mlx_new_image(vars->mlx, 68, 72);
	ash->left.addr = mlx_get_data_addr(ash->left.img, &ash->left.bits_per_pixel, &ash->left.line_length, &ash->left.endin);

	ash->right.img = mlx_new_image(vars->mlx, 68, 72);
	ash->right.addr = mlx_get_data_addr(ash->right.img, &ash->right.bits_per_pixel, &ash->right.line_length, &ash->right.endin);

	ash->back.img = mlx_new_image(vars->mlx, 68, 72);
	ash->back.addr = mlx_get_data_addr(ash->back.img, &ash->back.bits_per_pixel, &ash->back.line_length, &ash->back.endin);
}

void	get_ash(t_ash *ash, t_vars *vars)
{
	t_data	img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		h;

	h = 72;
	relative_path = "./imgs/ash.xpm";
	img_width = 272;
	img_height = 288;
	img.img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	creat_ash_images(ash, vars);
	copy_img(&ash->front, &img, 0, h * 0, 68, 72);
	copy_img(&ash->left, &img, 0, h * 1, 68, 72);
	copy_img(&ash->right, &img, 0, h * 2, 68, 72);
	copy_img(&ash->back, &img, 0, h * 3, 68, 72);
}