/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 14:42:11 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#define WIDTH 600
#define HEIGHT 450

void	get_map(t_game *game)
{
	game->map_frame.img = mlx_new_image(game->vars->mlx, WIDTH, HEIGHT);
	game->map_frame.addr = mlx_get_data_addr(game->map_frame.img, &game->map_frame.bits_per_pixel, &game->map_frame.line_length, &game->map_frame.endin);
	//void	copy_img(t_data *dest, t_data *src, int x_src, int y_src, int width, int height)
	copy_img(&game->map_frame, game->map, game->x, game->y, WIDTH, HEIGHT);
}

int	update_frame(t_game *game)
{
	get_map(game);
	mlx_clear_window(game->vars->mlx, game->vars->win);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->map_frame.img, 0, 0);
}

int	key_hook(int keycode, t_game *game)
{
	int		vel;

	vel = 10;
	if (keycode == W)
	{
		if (game->y > 0)
			game->y -= vel;
	}
	if (keycode == A)
	{
		if (game->x > 0)
			game->x -= vel;
	}
	if (keycode == S)
	{
		if (game->y < HEIGHT)
			game->y += vel;
	}
	if (keycode == D)
	{
		if (game->x < WIDTH)
			game->x += vel;
	}
}

int	main(void)
{
	t_vars	vars;
	t_game	game;
	t_data	map;
	int		width;
	int		height;

	width = 1120;
	height = 928;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Images");
	map.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/map.xpm", &width, &height);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endin);
	game.vars = &vars;
	game.map = &map;
	game.x = 0;
	game.y = 0;
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &game);
	mlx_loop_hook(vars.mlx, update_frame, &game);
	mlx_loop(vars.mlx);
	return (0);
}