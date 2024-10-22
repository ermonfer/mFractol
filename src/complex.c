/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 18:32:36 by fmontero          #+#    #+#             */
/*   Updated: 2024-10-16 18:32:36 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract-ol.h"
#include <stdio.h>

t_complex	c_add(t_complex a, t_complex b)
{
	return ((t_complex){a.re + b.re, a.im + b.im});
}

t_complex	c_mult(t_complex a, t_complex b)
{
	return ((t_complex){a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re});
}

t_complex	c_square(t_complex a)
{
	return ((t_complex){a.re * a.re - a.im * a.im, 2.0 * a.re * a.im});
}

double	c_modulus(t_complex a)
{
	return (sqrt(a.re * a.re + a.im * a.im));
}

t_uint	iter(t_complex z, t_complex c, t_uint check, t_uint limit)
{
	t_uint	count;

	if (c_modulus(z) > 2.0)
		return (0);
	count = 0;
	while (count++ < limit)
	{
		z = c_add(c_square(z), c);
		if ((count % check == 0) && (c_modulus(z) > 2.0))
			return (count);
	}
	return (limit);
}

t_complex pixel_to_complex(t_fractal *fractal, t_pixel pxl)
{
	t_complex	z;
	double		range;
	
	range = (fractal->br_c.re - fractal->tl_c.re);
	z.re = fractal->tl_c.re + (pxl.x / (double)fractal->img->width) * range;
	range = (fractal->tl_c.im - fractal->br_c.im);
	z.im = fractal->br_c.im + (pxl.y / (double)fractal->img->height) * range;
	return (z);
}

static void	hook(void *param)
{
	t_fractal	*fractal;
	t_pixel		pxl;
	t_complex	z;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_Y))
	{
		pxl = (t_pixel){0, 0};
		while (pxl.x < fractal->img->width)
		{
			pxl.y = 0;
			while (pxl.y < fractal->img->height)
			{
				z = pixel_to_complex(fractal, pxl);
				mlx_put_pixel(fractal->img, pxl.x, pxl.y, BLACK);
				pxl.y++;
			}
			pxl.x++;
		}
	}
}

int main(void)
{
	t_fractal fractal;

	t_uint width = 100;
	t_uint height = 100;

	fractal.mlx = mlx_init(width, height, "fract-ol", false);
	if (!fractal.mlx)
		exit(1);
	fractal.br_c = (t_complex){3.0, 0.0};
	fractal.tl_c = (t_complex){0.0, 3.0};
	fractal.img = mlx_new_image(fractal.mlx, width, height);
	t_pixel	pxl = (t_pixel){0, 0};
	t_complex z; 
	fractal.img = mlx_new_image(fractal.mlx, width, height);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	while (pxl.x < width)
	{
		pxl.y = 0;
		while (pxl.y <height)
		{
			z = pixel_to_complex(&fractal, pxl);
			printf("(%f, %f)\n", z.re, z.im);
			mlx_put_pixel(fractal.img, pxl.x, pxl.y, BRAT_GREEN);
			pxl.y++;
		}
		pxl.x++;
	}
	mlx_loop_hook(fractal.mlx, &hook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (0);
}