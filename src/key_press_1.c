/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:33 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:34 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press_move(int key, t_all *all)
{
	if (key == LEFT)
		all->control.move_left = 1;
	if (key == RIGHT)
		all->control.move_right = 1;
	if (key == UP)
		all->control.move_up = 1;
	if (key == DOWN)
		all->control.move_down = 1;
}

void	key_press_scale(int key, t_all *all)
{
	if (key == SMALLER)
		all->control.smaller = 1;
	if (key == BIGGER)
		all->control.bigger = 1;
}

void	key_press_rotation(int key, t_all *all)
{
	if (key == ROTATION_X)
		all->control.rotation_x = 1;
	if (key == ROTATION_Y)
		all->control.rotation_y = 1;
	if (key == ROTATION_Z)
		all->control.rotation_z = 1;
	if (key == ROTATION_X_REVERSE)
		all->control.rotation_x_reverse = 1;
	if (key == ROTATION_Y_REVERSE)
		all->control.rotation_y_reverse = 1;
	if (key == ROTATION_Z_REVERSE)
		all->control.rotation_z_reverse = 1;
}

void	key_press_height(int key, t_all *all)
{
	if (key == Z_PLUS)
	{
		all->control.z_plus = 1;
		all->control.z_moins = 0;
		all->control.z_defaut = 0;
	}
	if (key == Z_MOINS)
	{
		all->control.z_plus = 0;
		all->control.z_moins = 1;
		all->control.z_defaut = 0;
	}
	if (key == Z_DEFAUT)
	{
		all->control.z_plus = 0;
		all->control.z_moins = 0;
		all->control.z_defaut = 1;
	}
}
