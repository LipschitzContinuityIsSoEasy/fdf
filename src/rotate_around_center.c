/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_center.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:30:05 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:30:05 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialiser_point(t_data *center)
{
	center->x = 0;
	center->y = 0;
	center->z = 0;
}

void	rotate_around_center(t_data *point, t_data center, t_projection *p)
{
	point->x -= center.x;
	point->y -= center.y;
	point->z -= center.z;
	rotate_x(point, p->alpha);
	rotate_y(point, p->beta);
	rotate_z(point, p->gamma);
	point->x += center.x;
	point->y += center.y;
	point->z += center.z;
}
