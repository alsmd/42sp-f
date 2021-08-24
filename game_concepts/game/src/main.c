/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 18:11:08 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"


int	main(void)
{
	t_game		game;

	set_game(&game);
	//mlx_string_put(vars.mlx, vars.win, 50, 50, 0x0000FF00, "Hello World!");
	//mlx_mouse_hide(vars.mlx, vars.win);
	//mlx_mouse_hoxok(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, frame_update, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}