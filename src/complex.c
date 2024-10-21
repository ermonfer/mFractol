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

int main(void)
{
	t_fractal fractal;
	fractal.br_c = (t_complex){3.0, 0.0};
	fractal.tl_c = (t_complex){0.0, 3.0};
	fractal.img->width = 1000;
	fractal.img->height = 1000;
}