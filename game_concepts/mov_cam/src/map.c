/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:17:30 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 14:42:18 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	make_map(t_game *game)
{
	int		width;
	int		height;

	width = 1120;
	height = 928;
	
	game->x = 0;
	game->y = 0;
	game->map.img = mlx_xpm_file_to_image(game->vars->mlx, "./imgs/map.xpm", &width, &height);
	game->map.addr = mlx_get_data_addr(game->map.img, &game->map.bits_per_pixel, &game->map.line_length, &game->map.endin);
	game->map_frame.img = mlx_new_image(game->vars->mlx, WIDTH, HEIGHT);
	game->map_frame.addr = mlx_get_data_addr(game->map_frame.img, &game->map_frame.bits_per_pixel, &game->map_frame.line_length, &game->map_frame.endin);
	//void	copy_img(t_data *dest, t_data *src, int x_src, int y_src, int width, int height)
	//copy_img(&game->map_frame, game->map, game->x, game->y, WIDTH, HEIGHT);
}
