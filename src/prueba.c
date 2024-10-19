#include "../include/fract-ol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1024
#define HEIGHT 1024

void	hook(void* param)
{
	t_data* data;
	t_uint	x;
	t_uint	y;

	data = param; 
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_P))
		mlx_delete_image(data->mlx, data->image);
	x = 0;
	y = 0;
	while (x < data->image->width)
	{
		while (y < data->image->height)
		{
			mlx_put_pixel(data->image, x, y, BRAT_GREEN);
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
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.image = mlx_new_image(data.mlx, 1024, 1024);
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
