/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 18:16:09 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"



int	main(void)
{
	t_vars	vars;
	t_data	*active_sprit;
	t_data	bc;
	t_ash	ash;
	t_game	game;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1200, 600, "Images");
	get_ash(&ash, &vars);
	ash.active = 'f';
	ash.x = 0;
	ash.y = 0;
	ash.frame = 0;
	game.ash = &ash;
	game.vars = &vars;
	bc.img = mlx_new_image(vars.mlx, 1200, 600);
	bc.addr = mlx_get_data_addr(bc.img, &bc.bits_per_pixel, &bc.line_length, &bc.endin);
	game.background = &bc;
	clear_image(game.background, 1200, 600);
	//mlx_put_image_to_window(game.vars->mlx, game.vars->win, game.ash->back[0].img, game.ash->x, game.ash->y);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &game);
	mlx_loop_hook(vars.mlx, update_frame, &game);
	mlx_loop(vars.mlx);
	return (0);
}