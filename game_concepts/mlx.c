//#include <mlx.h>
#include "mlx/mlx.h"

typedef struct	s_data {
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
	
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "Hello World!");
	draw_square(mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}