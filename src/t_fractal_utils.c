/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fractal_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-20 14:57:49 by fmontero          #+#    #+#             */
/*   Updated: 2024-10-20 14:57:49 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract-ol.h"

t_fractal	init_fractal(char* name, t_fractal *fractal, int argc, char *av[])
{
	if (argc < 2)
		printf("mostrar opciones");
	else if (argc == 2)
	{
		if (strncpm(av[1], "mandelbrot", 11))
		{
			fractal->name = "mandelbrot"; //Mejor hacerlo con Enum como lo tiene carol
		}

	}
	 
}