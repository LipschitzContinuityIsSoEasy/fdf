/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_big_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:25 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:26 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_isometric_v2(t_data *iso_point, t_data *adjusted_point,
			t_all *all)
{
	if (all->control.view_2d_top)
	{
		iso_point->x = adjusted_point->x * all->p.scale + all->p.x_offset;
		iso_point->y = adjusted_point->y * all->p.scale + all->p.y_offset;
	}
	else if (all->control.view_2d_front || all->control.view_2d_right)
	{
		iso_point->x = adjusted_point->z * all->p.scale + all->p.x_offset;
		iso_point->y = adjusted_point->y * all->p.scale + all->p.y_offset;
	}
	else
	{
		all->p.tmp_x = adjusted_point->x * all->p.scale;
		all->p.tmp_y = adjusted_point->y * all->p.scale;
		iso_point->x = (all->p.tmp_x - all->p.tmp_y) * cos(all->p.angle)
			+ all->p.x_offset;
		iso_point->y = (all->p.tmp_x + all->p.tmp_y) * sin(all->p.angle)
			- adjusted_point->z * all->p.scale + all->p.y_offset;
	}
}

t_data	isometric_v2(t_data point, t_projection *p, t_all all)
{
	t_data	iso_point;
	float	adjusted_z;
	t_data	adjusted_point;

	adjusted_z = point.z;
	if (point.z > all.plat)
	{
		adjusted_z += all.new_var_z;
	}
	adjusted_point = point;
	adjusted_point.z = adjusted_z;
	rotate_x(&adjusted_point, p->alpha);
	rotate_y(&adjusted_point, p->beta);
	rotate_z(&adjusted_point, p->gamma);
	process_isometric_v2(&iso_point, &adjusted_point, &all);
	iso_point.z = adjusted_point.z;
	iso_point.color = point.color;
	return (iso_point);
}
