/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:48:22 by flavio            #+#    #+#             */
/*   Updated: 2021/08/26 10:01:45 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cord.h"
#include <stdio.h>
#include <math.h>
int	get_i(float i)
{
	int	index;
	int	temp;

	temp = i;
	index = 0;
	while (i <= 1)
	{
		index++;
		printf("%f", i);
		i += temp;
	}
	return (index);
}
/* 
void	draw_line(t_vars *vars, t_line *line)
{
	t_data	img;
	float		i;
	int			r;
	int			count;

	i = ((line->two.y - line->one.y) / (line->two.x - line->one.x));
	if (i < 1 && i > 0)
		r = get_i(i);
	else
		r = i;
	count = 0;
	printf("%d", r);
	img.img = mlx_new_image(vars->mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	
	while (line->one.x <= line->two.x)
	{
		if (count % r == 0)
			line->one.y += 1;
		my_mlx_pixel_put(&img, line->one.x, line->one.y, 0x0000FF);
		line->one.x += 1;
		count++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	
} */

void	define_cub(t_mesh *cub)
{
	cub->tris[0].p[0].x = 0;
	cub->tris[0].p[0].y = 0;
	cub->tris[0].p[0].z = 0;
	
	cub->tris[0].p[1].x = 0;
	cub->tris[0].p[1].y = 100;
	cub->tris[0].p[1].z = 0;

	cub->tris[0].p[2].x = 100;
	cub->tris[0].p[2].y = 0;
	cub->tris[0].p[2].z = 0;
}

int	main(void)
{
	t_vars	vars;
	t_mesh	cub = {
		//FRENTE		
		.tris[0] = {
			.p[0] = {
				.x = 0,
				.y = 0,
				.z = 0
			},
			.p[1] = {
				.x = 0,
				.y = 1,
				.z = 0
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 0
			}
		},
		.tris[1] = {
			.p[0] = {
				.x = 0,
				.y = 1,
				.z = 0
			},
			.p[1] = {
				.x = 1,
				.y = 1,
				.z = 0
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 0
			}
		},
		//Direita		
		.tris[2] = {
			.p[0] = {
				.x = 1,
				.y = 0,
				.z = 0
			},
			.p[1] = {
				.x = 1,
				.y = 1,
				.z = 0
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 1
			}
		},
		.tris[3] = {
			.p[0] = {
				.x = 1,
				.y = 1,
				.z = 0
			},
			.p[1] = {
				.x = 1,
				.y = 1,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 1
			}
		},
		//Tras		
		.tris[4] = {
			.p[0] = {
				.x = 0,
				.y = 0,
				.z = 1
			},
			.p[1] = {
				.x = 0,
				.y = 1,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 1
			}
		},
		.tris[5] = {
			.p[0] = {
				.x = 0,
				.y = 1,
				.z = 1
			},
			.p[1] = {
				.x = 1,
				.y = 1,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 1
			}
		},
		//Esquerda		
		.tris[6] = {
			.p[0] = {
				.x = 0,
				.y = 0,
				.z = 0
			},
			.p[1] = {
				.x = 0,
				.y = 1,
				.z = 0
			},
			.p[2] = {
				.x = 0,
				.y = 0,
				.z = 1
			}
		},
		.tris[7] = {
			.p[0] = {
				.x = 0,
				.y = 1,
				.z = 0
			},
			.p[1] = {
				.x = 0,
				.y = 1,
				.z = 1
			},
			.p[2] = {
				.x = 0,
				.y = 0,
				.z = 1
			}
		},
		//Cima		
		.tris[8] = {
			.p[0] = {
				.x = 0,
				.y = 1,
				.z = 0
			},
			.p[1] = {
				.x = 0,
				.y = 1,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 1,
				.z = 0
			}
		},
		.tris[9] = {
			.p[0] = {
				.x = 0,
				.y = 1,
				.z = 1
			},
			.p[1] = {
				.x = 1,
				.y = 1,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 1,
				.z = 0
			}
		},
		//Baixo		
		.tris[10] = {
			.p[0] = {
				.x = 0,
				.y = 0,
				.z = 0
			},
			.p[1] = {
				.x = 0,
				.y = 0,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 0
			}
		},
		.tris[11] = {
			.p[0] = {
				.x = 0,
				.y = 0,
				.z = 1
			},
			.p[1] = {
				.x = 1,
				.y = 0,
				.z = 1
			},
			.p[2] = {
				.x = 1,
				.y = 0,
				.z = 0
			}
		}
	};
	double	fNear = 0.1;// distancia mais proxima
	double	fFar = 1000;//Maxima profundidade
	double	fFov = 90.0;//Field of view
	double	fAspectRatio = ((double)600 / (double)800);
	double	fFovRad = 1.0 / tan(fFov * 0.5 / 180.0 * 3.14159);
	double	matrix[4][4] = {
		{fAspectRatio * fFovRad, 0, 0, 0},
		{0, fFovRad, 0, 0},
		{0, 0, fFar / (fFar - fNear), 1.0},
		{0, 0, (2 * fFar * fNear) / (fFar - fNear), 0},
	};
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "Cordenadas");
	int	index = 0;
	while  (index < 12)
	{
		t_triangle t_projected;
		t_projected = cub.tris[index];
		multiple(cub.tris[index].p[0], &t_projected.p[0], matrix);
		multiple(cub.tris[index].p[1], &t_projected.p[1], matrix);
		multiple(cub.tris[index].p[2], &t_projected.p[2], matrix);

		t_projected.p[0].x += 1.0;
		t_projected.p[0].y += 1.0;
		t_projected.p[1].x += 1.0;
		t_projected.p[1].y += 1.0;
		t_projected.p[2].x += 1.0;
		t_projected.p[2].y += 1.0;

		t_projected.p[0].x *= 0.5 * (float) 800;
		t_projected.p[0].y *= 0.5 * (float) 600;
		t_projected.p[1].x *= 0.5 * (float) 800;
		t_projected.p[1].y *= 0.5 * (float) 600;
		t_projected.p[2].x *= 0.5 * (float) 800;
		t_projected.p[2].y *= 0.5 * (float) 600;
		
		draw(t_projected.p[0].x, t_projected.p[0].y,
			t_projected.p[1].x, t_projected.p[1].y,
			t_projected.p[2].x, t_projected.p[2].y,
			&vars
		);
		index++;
	}

	mlx_loop(vars.mlx);

	return (0);
}

void	draw(double x1, double y1, double x2, double y2, double x3, double y3, t_vars *vars)
{
	t_data img;
	
	img.img = mlx_new_image(vars->mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endin);
	my_mlx_pixel_put(&img, x1 + 1, y1, 0x0000FF);
	my_mlx_pixel_put(&img, x1 + 2, y1, 0x0000FF);
	my_mlx_pixel_put(&img, x1 + 3, y1, 0x0000FF);
	my_mlx_pixel_put(&img, x2 + 1, y2, 0x0000FF);
	my_mlx_pixel_put(&img, x2 + 2, y2, 0x0000FF);
	my_mlx_pixel_put(&img, x2 + 3, y2, 0x0000FF);
	my_mlx_pixel_put(&img, x3 + 1, y3, 0x0000FF);
	my_mlx_pixel_put(&img, x3 + 2, y3, 0x0000FF);
	my_mlx_pixel_put(&img, x3 + 3, y3, 0x0000FF);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}
void	multiple(t_vec3d i, t_vec3d *o, double m[4][4])
{
	o->x = i.x * m[0][0] + i.y * m[1][0] + i.z * m[2][0] + m[3][0];
	o->y = i.x * m[0][1] + i.y * m[1][1] + i.z * m[2][1] + m[3][1];
	o->z = i.x * m[0][2] + i.y * m[1][2] + i.z * m[2][2] + m[3][2];
	float w = i.x * m[0][3] + i.y * m[1][3] + i.z * m[2][3] + m[3][3];
	if (w != 0.0)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}