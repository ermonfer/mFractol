/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-19 19:53:28 by fmontero          #+#    #+#             */
/*   Updated: 2024-10-19 19:53:28 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_color_grayscale(int iterations, int max_iterations)
{
    double t = (double)iterations / (double)max_iterations;
    int intensity = (int)(255 * ((double)iterations / (double)max_iterations));  // Valor en el rango 0-255
    return (intensity << 16) | (intensity << 8) | intensity;  // Mismo valor para r, g, b
}
