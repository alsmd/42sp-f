/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:14:25 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 18:05:57 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H
#define BACKGROUND 0x19d16f
#define W 119
#define A 97
#define S 115
#define D 100
#define TILE 64
#define WIDTH TILE * 15
#define HEIGHT TILE * 10
#include <X11/X.h>
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

typedef	struct	s_player
{
	int		x;
	int		y;
	t_data	sprites[4];
}	t_player;
typedef struct	s_map
{
	char	*array;
	t_data	img;
}	t_map;
typedef	struct	s_game
{
	t_vars		vars;
	t_map		map;
	t_player	player;
}	t_game;
/*Pixel Manipulation*/

//@brief	put a pixel in an image
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//@brief	get a pixel from a image
int		my_mlx_get_pixel(t_data *data, int x, int y);

//@brief	get part of the image src and paste on the image dest
void	copy_img_from(t_data *dest, t_data *src, int x_src, int y_src, int width, int height);

//@brief	get an image src and paste in a specific locations of dest
void	copy_img_to(t_data *dest, t_data *src, int x_dest, int y_dest, int width, int height);

/*Actions*/
//@brief	clean an image with a color
void	clear_image(t_data *img, int width, int height, int color);

/*Map*/
char	*get_map(int w, int h, char *map_path);
void	render_map(char *map, t_vars *vars, t_data *map_img, int w, int h);

#endif