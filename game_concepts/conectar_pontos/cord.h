#include "mlx/mlx.h"
#include <X11/X.h>
typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_ponto
{
	int	x;
	int	y;
}	t_ponto;
typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
} t_vec3d;

typedef struct s_triangle
{
	t_vec3d	p[3];
}	t_triangle;

typedef struct s_mesh
{
	t_triangle	tris[12];
}	t_mesh;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endin;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_get_pixel(t_data *data, int x, int y);
void	copy_img_from(t_data *dest, t_data *src, int x_src, int y_src, int width, int height);
void	copy_img_to(t_data *dest, t_data *src, int x_dest, int y_dest, int width, int height);
void	multiple(t_vec3d i, t_vec3d *o, double m[4][4]);
void	draw(double x1, double y1, double x2, double y2, double x3, double y3, t_vars *vars);
