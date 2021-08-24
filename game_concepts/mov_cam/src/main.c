/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 14:47:45 by flavio           ###   ########.fr       */
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
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Images");
	get_ash(&ash, &vars);
	game.ash = &ash;
	game.vars = &vars;
	make_map(&game);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &game);
	mlx_loop_hook(vars.mlx, update_frame, &game);
	mlx_loop(vars.mlx);
	return (0);
}