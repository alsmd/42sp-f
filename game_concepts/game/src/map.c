/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:48:08 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 17:52:45 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

char	*get_map(int w, int h, char *map_path)
{
	char	*map;
	char	c;
	int		index;
	int		fd;

	index = 0;
	map = (char *) malloc((w * h) + 1);
	fd = open(map_path, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '1' || c == '0')
		{
			map[index] = c;
			index++;
		}
	}
	close(fd);
	return (map);
}

void	render_map(char *map, t_vars *vars, t_data *map_img, int w, int h)
{
	t_data	map_tile;
	int		x;
	int		y;
	int		size;
	
	size = TILE;
	x = 0;
	y = 0;
	map_img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bits_per_pixel, &map_img->line_length, &map_img->endin);
	map_tile.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &size, &size);
	map_tile.addr = mlx_get_data_addr(map_tile.img, &map_tile.bits_per_pixel, &map_tile.line_length, &map_tile.endin);
	while (x < w)
	{
		while (y < h)
		{
			if (map[(y * w) + x] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, map_tile.img, x * TILE, y * TILE);
				copy_img_to(map_img, &map_tile, x * TILE, y * TILE, TILE, TILE);
			}
			y++;
		}
		y = 0;
		x++;
	}
}