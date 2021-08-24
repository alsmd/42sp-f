/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:14:25 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 15:59:27 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H
#define BACKGROUND 0x19d16f
#define W 119
#define A 97
#define S 115
#define D 100
#define WIDTH 600
#define HEIGHT 420
#include <X11/X.h>
#include "../mlx/mlx.h"
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endin;
}	t_data;
typedef struct s_ash
{
	t_data	front[4];
	t_data	left[4];
	t_data	right[4];
	t_data	back[4];
	int		frame;
	char	active;
	int		x;
	int		y;
}	t_ash;

typedef struct s_game
{
	t_ash	*ash;
	t_data	map;
	t_data	map_frame;
	t_vars	*vars;
	int		x;
	int		y;
}	t_game;

/*Pixel Manipulation*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_get_pixel(t_data *data, int x, int y);
void	copy_img(t_data *dest, t_data *src, int x_src, int y_src, int width, int height);
void	copy_img_to(t_data *dest, t_data *src, int x_src, int y_src, int width, int height);

/*Make sure*/
void	get_ash(t_ash *ash, t_vars *vars);

/*Actions*/
int	key_hook(int keycode, t_game *game);
int	update_frame(t_game *game);
void	clear_image(t_data *img, int width, int height, int color);
/*Maps*/
void	make_map(t_game *game);

#endif