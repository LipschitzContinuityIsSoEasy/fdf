/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:37 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:38 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press_view_part1(int key, t_all *all)
{
	if (key == VIEW_2D_TOP)
	{
		all->control.view_2d_top = 1;
		all->control.view_2d_front = 0;
		all->control.view_2d_right = 0;
		all->control.view_defaut = 0;
		all->p.alpha = 0.0f;
		all->p.beta = 0.0f;
		all->p.gamma = 0.0f;
	}
	if (key == VIEW_DEFAUT)
	{
		all->control.view_2d_top = 0;
		all->control.view_2d_front = 0;
		all->control.view_2d_right = 0;
		all->control.view_defaut = 1;
	}
}

void	key_press_view_part2(int key, t_all *all)
{
	if (key == VIEW_2D_FRONT)
	{
		all->control.view_2d_top = 0;
		all->control.view_2d_front = 1;
		all->control.view_2d_right = 0;
		all->control.view_defaut = 0;
		all->p.alpha = 1.570796f;
		all->p.beta = 0.0f;
		all->p.gamma = 0.0f;
	}
	if (key == VIEW_2D_RIGHT)
	{
		all->control.view_2d_top = 0;
		all->control.view_2d_front = 0;
		all->control.view_2d_right = 1;
		all->control.view_defaut = 0;
		all->p.alpha = 0.0f;
		all->p.beta = 1.570796f;
		all->p.gamma = -1.570796f;
	}
}

void	key_press_color(int key, t_all *all)
{
	if (key == COLOR_CHANGE)
	{
		all->control.color_change = 1;
		all->control.color_varier_active = 0;
		all->color_random = rand() % 255;
	}
	if (key == COLOR_DEFAUT)
	{
		all->control.color_change = 0;
		all->control.color_varier_active = 0;
	}
	if (key == COLOR_VARIER)
	{
		all->control.color_varier_active = 1;
		all->control.color_change = 0;
	}
}

void	key_press_mouse(int key, t_all *all)
{
	if (key == MOUSE_ACTIVE && ft_max(all->cols, all->rows) <= 51)
	{
		all->control.mouse_active = 1;
	}
	if (key == MOUSE_DESACTIVE)
	{
		all->control.mouse_active = 0;
	}
}

int	key_press(int key, t_all *all)
{
	if (key == ESC || key == QUIT)
		return (ft_close(all));
	key_press_move(key, all);
	key_press_scale(key, all);
	key_press_rotation(key, all);
	key_press_height(key, all);
	key_press_view_part1(key, all);
	key_press_view_part2(key, all);
	key_press_color(key, all);
	key_press_mouse(key, all);
	return (0);
}
