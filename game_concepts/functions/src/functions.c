/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:26 by flavio            #+#    #+#             */
/*   Updated: 2021/08/22 14:28:19 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#define WIDTH 600
#define HEIGHT 450
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	mlx_mouse_show(vars->mlx, vars->win);
	mlx_mouse_move(vars->mlx, vars->win, x + 50, y + 50);
	printf("Button: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}

int	update(t_vars *vars)
{
	int	x;
	int	y;
	
	//mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	printf("x:%d, y:%d\n", x, y);
}
int	main(void)
{
	t_vars		vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Images");
	mlx_string_put(vars.mlx, vars.win, 50, 50, 0x0000FF00, "Hello World!");
	//mlx_mouse_hide(vars.mlx, vars.win);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
	return (0);
}