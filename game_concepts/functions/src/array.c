/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 15:45:36 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#define TILE 64
#define WIDTH TILE * 15
#define HEIGHT TILE * 10

char	*get_map()
{
	char	*map;
	char	c;
	int		index;
	int		fd;

	index = 0;
	map = (char *) malloc((15 * 10) + 1);
	fd = open("./src/map", O_RDONLY);
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

void	render_map(char *map, t_vars *vars, t_data *map_img)
{
	t_data	map_tile;
	int		w;
	int		h;
	int		x;
	int		y;

	w = TILE;
	h = TILE;
	x = 0;
	y = 0;
	map_img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bits_per_pixel, &map_img->line_length, &map_img->endin);
	map_tile.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &w, &h);
	map_tile.addr = mlx_get_data_addr(map_tile.img, &map_tile.bits_per_pixel, &map_tile.line_length, &map_tile.endin);
	while (x < 15)
	{
		while (y < 10)
		{
			if (map[(y * 15) + x] == '1')
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
int	main(void)
{
	t_vars		vars;
	t_data		map_img;
	char		*map;
	int			x;
	int			y;

	x = 0;
	y = 0;	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Images");
	map = get_map();
	render_map(map, &vars, &map_img);
	//mlx_put_image_to_window(vars.mlx, vars.win, map_img.img, 0, 0);
	while (y < 10)
	{
		while (x < 15)
		{
			printf("%d ", map[(y * 15) + x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
	//mlx_string_put(vars.mlx, vars.win, 50, 50, 0x0000FF00, "Hello World!");
	//mlx_mouse_hide(vars.mlx, vars.win);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
	return (0);
}