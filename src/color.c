/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:28 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/21 14:05:09 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract-ol.h"

int	get_color_grayscale(int iterations, int max_iterations)
{
	int intensity;
	intensity = 255 - (int)(255 * (iterations / (double)max_iterations));
	return (intensity << 24 | intensity << 16 | intensity << 8 | 0xFF);
}

int	get_color_three_colors(int iterations, int max_iterations)
{
	double t = iterations / (double)max_iterations;
	int r;
	int g;
	int b;

	if (t < 0.5)
	{
		t *= 2;
		r = 0;
		g = (int)(t * 255);
		b = (int)((1 - t) * 255);
	}
	else
	{
		t = (t - 0.5) * 2;
		r = (int)(t * 255);
		g = (int)((1 - t) * 255);
		b = 0;
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
