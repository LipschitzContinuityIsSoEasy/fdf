/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:06 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:07 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 5 fonctions pour gradient de couleur */
int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return ((color & 0xFF));
}

int	interpolate_color(int color1, int color2, float fraction)
{
	t_color_gradient	rgb_color;

	rgb_color.r1 = get_red(color1);
	rgb_color.g1 = get_green(color1);
	rgb_color.b1 = get_blue(color1);
	rgb_color.r2 = get_red(color2);
	rgb_color.g2 = get_green(color2);
	rgb_color.b2 = get_blue(color2);
	rgb_color.r = (int)(rgb_color.r1
			+ (rgb_color.r2 - rgb_color.r1) * fraction);
	rgb_color.g = (int)(rgb_color.g1
			+ (rgb_color.g2 - rgb_color.g1) * fraction);
	rgb_color.b = (int)(rgb_color.b1
			+ (rgb_color.b2 - rgb_color.b1) * fraction);
	return ((rgb_color.r << 16) | (rgb_color.g << 8) | rgb_color.b);
}

float	calculate_fraction(float x1, float x2, float x)
{
	if (x1 != x2)
	{
		return ((x - x1) / (x2 - x1));
	}
	return (0);
}
