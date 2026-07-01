/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:30:01 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:30:01 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialiser_projection(t_projection *p)
{
	p->scale = 1;
	p->x_offset = WIDTH / 3;
	p->y_offset = HEIGHT / 4;
	p->angle = 0.523599;
	p->tmp_x = 0;
	p->tmp_y = 0;
	p->alpha = 0;
	p->beta = 0;
	p->gamma = 0;
}

void	rotate_z(t_data *point, float gamma)
{
	float	tmp;

	tmp = point->x;
	point->x = tmp * cos(gamma) - point->y * sin(gamma);
	point->y = tmp * sin(gamma) + point->y * cos(gamma);
}

void	rotate_y(t_data *point, float beta)
{
	float	tmp;

	tmp = point->x;
	point->x = tmp * cos(beta) + point->z * sin(beta);
	point->z = point->z * cos(beta) - tmp * sin(beta);
}

void	rotate_x(t_data *point, float alpha)
{
	float	tmp;

	tmp = point->y;
	point->y = tmp * cos(alpha) - point->z * sin(alpha);
	point->z = tmp * sin(alpha) + point->z * cos(alpha);
}

t_data	calculate_center(t_data **tab, int rows, int cols)
{
	t_data	center;
	int		row;
	int		col;
	int		total_points;

	row = 0;
	col = 0;
	initialiser_point(&center);
	total_points = rows * cols;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			center.x += tab[row][col].x;
			center.y += tab[row][col].y;
			center.z += tab[row][col].z;
			col++;
		}
		row++;
	}
	center.x /= total_points;
	center.y /= total_points;
	center.z /= total_points;
	return (center);
}
