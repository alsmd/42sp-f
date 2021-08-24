#include <mlx.h>
#include <X11/X.h>
#include "mlx/mlx.h"
#include <stdio.h>
#define W 119
#define A 97
#define S 115
#define D 100


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
	int		x;
	int		y;
	int		endin;
}	t_data;
typedef struct s_game
{
	t_data	*img;
	t_vars	*vars;
}	t_game;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void	draw_square(t_data *img,int x, int y)
{
	int	x_final;
	int	y_final;
	int	x_begin;
	int	y_begin;

	x_final = x + 100;
	y_final = y + 100;
	x_begin = x;
	y_begin = y;
	while (x < x_final)
	{
		while (y < y_final)
		{
			my_mlx_pixel_put(img, x, y, 0x009c9e);
			y++;
		}
		y = y_begin;
		x++;
	}
	/* while (x < x_final)
	{
		my_mlx_pixel_put(img, x, y, 0x009c9e);
		x++;
	}
	while (y < y_final)
	{
		my_mlx_pixel_put(img, x, y, 0x009c9e);
		y++;
	}
	while (x > x_begin)
	{
		my_mlx_pixel_put(img, x, y, 0x009c9e);
		x--;
	}
	while (y > y_begin)
	{
		my_mlx_pixel_put(img, x, y, 0x009c9e);
		y--;
	} */
}


void	clear_image(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;	
	while (x < 1200)
	{
		while (y < 600)
		{
			my_mlx_pixel_put(img, x, y, 0x19d16f);
			y++;
		}
		y = 0;
		x++;
	}
}

int	update_frame(t_game *game)
{
	clear_image(game->img);
	//mlx_clear_window(game->vars->mlx, game->vars->win);
	draw_square(game->img, game->img->x, game->img->y);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->img->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	int	velocidade;

	velocidade = 25;
	if (keycode == 65307)
		mlx_destroy_window(game->vars->mlx, game->vars->win);
	if (keycode == W)
		game->img->y -= velocidade;
	if (keycode == A)
		game->img->x -= velocidade;
	if (keycode == S)
		game->img->y += velocidade;
	if (keycode == D)
		game->img->x += velocidade;
	printf("ok%d\n", keycode);
}


int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_game	game;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1200, 600, "It is not a game!");
	img.img = mlx_new_image(vars.mlx, 1200, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	game.vars = &vars;
	game.img = &img;
	game.img->x = 0;
	game.img->y = 0;
	//mlx_clear_window(vars.mlx, vars.win);
	//draw_square(&img, 200, 0);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop_hook(vars.mlx, update_frame, &game);
	//mlx_khookhook(vars.win, key_hook, &game);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &game);
	mlx_loop(vars.mlx);
	return (0);
}
