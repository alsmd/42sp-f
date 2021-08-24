/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 10:36:06 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#define WIDTH 600
#define HEIGHT 450

typedef	struct	s_dragon
{
	t_data		sprites[4];
	t_vars		*vars;
	int			w;
	int			h;
	int			i;
	long int	time;
	long int	delay;
}	t_dragon;


int	update(t_dragon *dragon)
{
	dragon->delay = clock();
	if (dragon->delay > dragon->time + (CLOCKS_PER_SEC / 6))
	{
		mlx_put_image_to_window(dragon->vars->mlx, dragon->vars->win, dragon->sprites[dragon->i].img, 0, 0);
		if (dragon->i < 3)
			dragon->i += 1;
		else
			dragon->i = 0;
		dragon->time = clock();
	}
}
void	make_dragon(t_dragon *dragon, t_data *img, t_vars *vars)
{
	int	x;

	x = 0;
	dragon->w = 32;
	dragon->h = 32;
	while (x < 4)
	{
		dragon->sprites[x].img = mlx_new_image(vars->mlx, dragon->w, dragon->h);
		dragon->sprites[x].addr = mlx_get_data_addr(dragon->sprites[x].img, &dragon->sprites[x].bits_per_pixel, &dragon->sprites[x].line_length, &dragon->sprites[x].endin);
		copy_img(&dragon->sprites[x], img, dragon->w * x, 0, dragon->w, dragon->h);
		x++;
	}
}

int	main(void)
{
	t_vars		vars;
	t_dragon	dragon;
	t_data		img;
	int			w;
	int			h;
	
	w = 128;
	h = 256;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Images");
	img.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/BlueDragon.xpm", &w, &h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	make_dragon(&dragon, &img, &vars);
	dragon.time = clock();
	dragon.vars = &vars;
	dragon.i = 0;
	mlx_loop_hook(vars.mlx, update, &dragon);
	mlx_loop(vars.mlx);

	/* printf("%ld\n", clock());
	sleep(1);
	printf("%ld\n", clock()); */
	return (0);
}