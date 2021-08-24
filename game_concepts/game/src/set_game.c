/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:06:38 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 18:13:45 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	set_player(t_game *game)
{
	int	i;

	game->player.x = 0;
	game->player.x = 1;
	while (i < 4)
	{

	}
}

void	set_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, WIDTH, HEIGHT, "Plataforma");
	game->map.array = get_map(15, 10, "./src/map");
	set_player(game);
}