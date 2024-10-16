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

# include <math.h>
# include <stdbool.h>

typedef unsigned int t_uint;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

t_complex	c_add(t_complex a, t_complex b);
t_complex	c_mult(t_complex a, t_complex b);
t_complex	c_square(t_complex a);
double		c_modulus(t_complex a);
#endif
