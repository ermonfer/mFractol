#include "../include/fract-ol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1024
#define HEIGHT 1024

void	hook(void* param)
{
	t_fractal*	fractal;
	t_uint		x;
	t_uint		y;

	fractal = param; 
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_P))
		mlx_delete_img(fractal->mlx, fractal->img);
	x = 0;
	y = 0;
	while (x < fractal->img->width)
	{
		while (y < fractal->img->height)
		{
			mlx_put_pixel(fractal->img, x, y, BRAT_GREEN);
			y++;
		}
		y = 0;
		x++;
	}
}

int32_t	main(void)
{
	t_fractal		fractal;

	fractal.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!fractal.mlx)
		exit(EXIT_FAILURE);
	fractal.img = mlx_new_img(fractal.mlx, 1024, 1024);
	mlx_img_to_window(fractal.mlx, fractal.img, 0, 0);
	mlx_loop_hook(fractal.mlx, &hook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
