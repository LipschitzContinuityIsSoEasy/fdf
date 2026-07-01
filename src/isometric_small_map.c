/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_small_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:29 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:30 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_isometric(t_data *adjusted_point, t_data *projected_point,
			t_all *all)
{
	if (all->control.view_2d_top)
	{
		projected_point->x = adjusted_point->x * all->p.scale + all->p.x_offset;
		projected_point->y = adjusted_point->y * all->p.scale + all->p.y_offset;
	}
	else if (all->control.view_2d_front || all->control.view_2d_right)
	{
		projected_point->x = adjusted_point->z * all->p.scale + all->p.x_offset;
		projected_point->y = adjusted_point->y * all->p.scale + all->p.y_offset;
	}
	else if (all->control.view_defaut)
	{
		all->p.tmp_x = adjusted_point->x * all->p.scale;
		all->p.tmp_y = adjusted_point->y * all->p.scale;
		projected_point->x = (all->p.tmp_x - all->p.tmp_y) * cos(all->p.angle)
			+ all->p.x_offset;
		projected_point->y = (all->p.tmp_x + all->p.tmp_y) * sin(all->p.angle)
			- adjusted_point->z * all->p.scale + all->p.y_offset;
	}
}

t_data	isometric(t_data point, t_projection *p, t_all all)
{
	t_data	projected_point;
	t_data	center;
	float	adjusted_z;
	t_data	adjusted_point;

	center = calculate_center(all.tab, all.rows, all.cols);
	adjusted_z = point.z;
	if (all.new_var_z != all.plat)
	{
		if (point.z > all.plat)
		{
			adjusted_z += all.new_var_z;
		}
		else if (point.z < all.plat)
		{
			adjusted_z -= all.new_var_z;
		}
	}
	adjusted_point = point;
	adjusted_point.z = adjusted_z;
	rotate_around_center(&adjusted_point, center, p);
	process_isometric(&adjusted_point, &projected_point, &all);
	projected_point.z = adjusted_point.z;
	projected_point.color = point.color;
	return (projected_point);
}
