/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:36:42 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 08:06:21 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	key_hook(int keycode, t_game *game)
{
	int	vel;

	vel = 15;
	if (keycode == D || keycode == S || keycode == A || keycode == W)
	{
		game->ash->frame +=1;
		if (game->ash->frame > 3)
			game->ash->frame = 0;
	}
	if (keycode == D)
	{
		if (game->ash->x >= WIDTH / 2 && game->x < WIDTH)
			game->x += vel;
		else if (game->ash->x < WIDTH - 50)
			game->ash->x += vel;
		game->ash->active = 'r';
	}
	if (keycode == S)
	{
		if (game->ash->y >= HEIGHT / 2 && game->y < HEIGHT)
			game->y += vel;
		else if (game->ash->y < HEIGHT - 70)
			game->ash->y += vel;
		game->ash->active = 'f';
	}
	if (keycode == A)
	{
		if (game->ash->x < WIDTH / 2 && game->x > 0)
			game->x -= vel;
		else if (game->ash->x > 0)
			game->ash->x -= vel;
		game->ash->active = 'l';
	}
	if (keycode == W)
	{
		if (game->ash->y < HEIGHT / 2 && game->y > 0)
			game->y -= vel;
		else if (game->ash->y > 0)
			game->ash->y -= vel;
		game->ash->active = 'b';
	}
}

int	update_frame(t_game *game)
{
	copy_img(&game->map_frame, &game->map, game->x, game->y, WIDTH, HEIGHT);
	//mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->background->img, 0, 0);
	if (game->ash->active == 'f')
		copy_img_to(&game->map_frame, &game->ash->front[game->ash->frame], game->ash->x, game->ash->y, 68, 72);
		//mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->front[game->ash->frame].img, game->ash->x, game->ash->y);
	if (game->ash->active == 'l')
		copy_img_to(&game->map_frame, &game->ash->left[game->ash->frame], game->ash->x, game->ash->y, 68, 72);
		//mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->left[game->ash->frame].img, game->ash->x, game->ash->y);
	if (game->ash->active == 'r')
		copy_img_to(&game->map_frame, &game->ash->right[game->ash->frame], game->ash->x, game->ash->y, 68, 72);
//		mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->right[game->ash->frame].img, game->ash->x, game->ash->y);
	if (game->ash->active == 'b')
		copy_img_to(&game->map_frame, &game->ash->back[game->ash->frame], game->ash->x, game->ash->y, 68, 72);
//		mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->ash->back[game->ash->frame].img, game->ash->x, game->ash->y);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->map_frame.img, 0, 0);
	
}