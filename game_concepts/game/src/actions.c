/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:08:08 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 18:09:11 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	frame_update(t_game *game)
{
	render_map(game->map.array, &game->vars, &game->map.img, 15, 10);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->map.img.img, 0, 0);
}
