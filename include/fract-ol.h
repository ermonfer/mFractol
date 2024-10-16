/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 18:00:02 by fmontero          #+#    #+#             */
/*   Updated: 2024-10-16 18:00:02 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>

//Colors
# define BLACK       		0x000000FF
# define WHITE       		0xFFFFFFFF
// Psychedelic colors
# define NEON_ORANGE     	0xFF6600FF
# define PSYCHEDELIC_PURPLE	0x660066FF
# define AQUA_DREAM			0x33CCCCFF
# define HOT_PINK        	0xE55982FF 
# define CYAN_ELECTRIC		0xFF2CFFFF
# define MCDONALDS			0xFFC72CFF
# define SUPER_YELLOW		0xFCBE11FF
# define PNKY_PASTEL		0xFFC4D6FF
# define CUTE_GREEN			0xC1E378FF

typedef unsigned int t_uint;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_complex		z;
	t_complex		c;
	int				color_theme;
	int				color_index;
}	t_data;

t_complex	c_add(t_complex a, t_complex b);
t_complex	c_mult(t_complex a, t_complex b);
t_complex	c_square(t_complex a);
double		c_modulus(t_complex a);
t_uint		iter(t_complex z, t_complex c, t_uint check, t_uint limit);
#endif
