/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:36:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 17:37:21 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	key_hook(int keycode, t_game *game)
{
	int	vel;

	vel = 50;
	if (keycode == D)
	{
		if (game->ash->x < 1200 - 50)
			game->ash->x += vel;
		game->ash->active = 'r';
	}
	if (keycode == S)
	{
		if (game->ash->y < 600 - 70)
			game->ash->y += vel;
		game->ash->active = 'f';
	}
	if (keycode == A)
	{
		if (game->ash->x > 25)
			game->ash->x -= vel;
		game->ash->active = 'l';
	}
	if (keycode == W)
	{
		if (game->ash->y > 25)
			game->ash->y -= vel;
		game->ash->active = 'b';
	}
}

int	update_frame(t_game *game)
{
	mlx_clear_window(game->vars->mlx, game->vars->win);
	if (game->ash->active == 'f')
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->front.img, game->ash->x, game->ash->y);
	if (game->ash->active == 'l')
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->left.img, game->ash->x, game->ash->y);
	if (game->ash->active == 'r')
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->right.img, game->ash->x, game->ash->y);
	if (game->ash->active == 'b')
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->back.img, game->ash->x, game->ash->y);
}