#include "../include/fract-ol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1024
#define HEIGHT 1024

static mlx_image_t	*g_img;

void	hook(void* param)
{
	mlx_t*	mlx;
	t_uint	x;
	t_uint	y;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);
	x = 0;
	y = 0;
	while (x < g_img->width)
	{
		while (y < g_img->height)
		{
			mlx_put_pixel(g_img, x, y, PNKY_PASTEL);
			y++;
		}
		y = 0;
		x++;
	}
}

int32_t	main(void)
{
	t_data		data;
	data.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 1024, 1024);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
