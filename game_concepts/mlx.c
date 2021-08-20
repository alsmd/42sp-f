#include <mlx.h>
#include <X11/X.h>
#include "mlx/mlx.h"
#include <stdio.h>

/* typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(void *mlx, void *mlx_win)
{
	int		x;
	int		y;
	t_data	img;

	x = 0;
	y = 0;
	img.img = mlx_new_image(mlx, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 750)
		my_mlx_pixel_put(&img, x, x++, 0x00FF0000);
	x = 0;
	while (x < 750)
		my_mlx_pixel_put(&img, x + 10, x++, 0xe86402);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		x = 0;
	while (x < 750)
		my_mlx_pixel_put(&img, x + 20, x++, 0xe86402);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
} */

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "Hello World!");
	draw_square(mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
} */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endin;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void  set_background(t_data *img, int width, int height, int color)
{
	int	x;
	int	y;
	int	hold;

	x = 0;
	y = 0;
	hold = color;
	while (x < width)
	{
		while (y < height)
		{
			if (y % 50 == 0)
				color++;
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		color = hold;
		y = 0;
		x++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	printf("%d\n", keycode);
}

void	enter_window(long int keycode, t_vars *vars)
{
	printf("Hello World!%ld\n", keycode);

}

void	leave_window(long int keycode, t_vars *vars)
{
	printf("Bye Bye World!%ld\n", keycode);

}

int	move(int keycode,int y, t_vars *vars)
{
	printf("%d\n", y);
}

int	render_next_frame(void *vars)
{
	printf("1");
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_hook(vars.win, KeyRelease, KeyReleaseMask, key_hook, &vars);
	//mlx_hook(vars.win, EnterNotify, EnterWindowMask, enter_window, &vars);
	//mlx_hook(vars.win, LeaveNotify, LeaveWindowMask, leave_window, &vars);
	//mlx_hook(vars.win, MotionNotify, ButtonMotionMask, move, &vars);
	//mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}






/* int	main(void)
{
	t_vars	vars;
	int		index;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1200, 600, "My window");
	img.img = mlx_new_image(vars.mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	set_background(&img, 600, 300, 0xee3939);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 300);


	img.img = mlx_new_image(vars.mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	set_background(&img, 600, 300, 0x44c8b4);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	while (1)
	{
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop(vars.win);
	}	
	return (0);
} */
//y = 2 x = 3
//offset = y * 2000 + 3 * (4)
//4000