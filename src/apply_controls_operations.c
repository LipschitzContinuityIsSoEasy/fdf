/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_controls_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:28:33 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:28:41 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_controls_move(t_all *all)
{
	if (all->control.move_left)
		all->p.x_offset += 10;
	if (all->control.move_right)
		all->p.x_offset -= 10;
	if (all->control.move_up)
		all->p.y_offset -= 10;
	if (all->control.move_down)
		all->p.y_offset += 10;
}

void	apply_controls_scale(t_all *all)
{
	if (all->control.smaller)
		all->p.scale -= 1;
	if (all->control.bigger)
		all->p.scale += 1;
	if (all->p.scale < 1)
		all->p.scale = 1;
}

void	apply_controls_rotation(t_all *all)
{
	if (all->control.rotation_x)
		all->p.alpha += 0.1;
	if (all->control.rotation_y)
		all->p.beta += 0.1;
	if (all->control.rotation_z)
		all->p.gamma += 0.1;
	if (all->control.rotation_x_reverse)
		all->p.alpha -= 0.1;
	if (all->control.rotation_y_reverse)
		all->p.beta -= 0.1;
	if (all->control.rotation_z_reverse)
		all->p.gamma -= 0.1;
}

void	apply_controls_height(t_all *all)
{
	if (all->control.z_plus && ft_max(all->rows, all->cols) <= 51)
		all->new_var_z += 0.1f;
	if (all->control.z_plus && ft_max(all->rows, all->cols) > 51)
		all->new_var_z += 4.0f;
	if (all->control.z_moins && ft_max(all->rows, all->cols) <= 51)
		all->new_var_z -= 0.1f;
	if (all->control.z_moins && ft_max(all->rows, all->cols) > 51)
		all->new_var_z -= 4.0f;
	if (all->control.z_defaut)
		all->new_var_z = 0.0f;
}

void	apply_controls_color(t_all *all)
{
	if (all->control.color_varier_active)
	{
		all->color_random += rand() % 255;
	}
}
