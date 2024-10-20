/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:00:02 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/20 01:54:58 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>

# define MAX_ITER 800
# define CHECK 1
//Colors
# define BLACK       		0x000000FF
# define WHITE       		0xFFFFFFFF
# define NEON_ORANGE     	0xFF6600FF
# define PSYCHEDELIC_PURPLE	0x660066FF
# define AQUA_DREAM			0x33CCCCFF
# define HOT_PINK        	0xE55982FF 
# define CYAN_ELECTRIC		0xFF2CFFFF
# define MCDONALDS			0xFFC72CFF
# define SUPER_YELLOW		0xFCBE11FF
# define PNKY_PASTEL		0xFFC4D6FF
# define CUTE_GREEN			0xC1E378FF
# define BRAT_GREEN			0x89CC04FF

typedef unsigned int t_uint;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_complex		tl_c;
	t_complex		br_c;
	char*			name;
	t_complex		z;
	t_complex		v;
}	t_fractal;

typedef struct s_pixel
{
	t_uint x;
	t_uint y;
}	t_pixel;

t_complex	c_add(t_complex a, t_complex b);
t_complex	c_mult(t_complex a, t_complex b);
t_complex	c_square(t_complex a);
double		c_modulus(t_complex a);
t_complex	pixel_to_complex(t_fractal *fractal, t_pixel pixel);
t_uint		iter(t_complex z, t_complex c, t_uint check, t_uint limit);

int			get_color_grayscale(int iterations, int max_iterations);
int			get_color_three_colors(int iterations, int max_iterations);
int			get_color(t_pixel plx, t_uint max_iter);

void		hook(void* param);
t_fractal	init_fractal(char* name);
#endif
