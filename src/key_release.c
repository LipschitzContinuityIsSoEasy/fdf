/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:42 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:43 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_release_rotation_height_color(int key, t_all *all)
{
	if (key == ROTATION_X)
		all->control.rotation_x = 0;
	if (key == ROTATION_Y)
		all->control.rotation_y = 0;
	if (key == ROTATION_Z)
		all->control.rotation_z = 0;
	if (key == ROTATION_X_REVERSE)
		all->control.rotation_x_reverse = 0;
	if (key == ROTATION_Y_REVERSE)
		all->control.rotation_y_reverse = 0;
	if (key == ROTATION_Z_REVERSE)
		all->control.rotation_z_reverse = 0;
	if (key == Z_PLUS)
		all->control.z_plus = 0;
	if (key == Z_MOINS)
		all->control.z_moins = 0;
	if (key == COLOR_VARIER)
		all->control.color_change = 1;
}

int	key_release(int key, t_all *all)
{
	if (key == LEFT)
		all->control.move_left = 0;
	if (key == RIGHT)
		all->control.move_right = 0;
	if (key == UP)
		all->control.move_up = 0;
	if (key == DOWN)
		all->control.move_down = 0;
	if (key == SMALLER)
		all->control.smaller = 0;
	if (key == BIGGER)
		all->control.bigger = 0;
	key_release_rotation_height_color(key, all);
	return (0);
}
