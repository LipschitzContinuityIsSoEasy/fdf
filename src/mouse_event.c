/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:50 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:50 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move(int x, int y, t_all *all)
{
	if (all->control.mouse_active)
	{
		all->p.alpha = (y % 360) * 0.01f;
		all->p.beta = (x % 360) * 0.01f;
		all->p.gamma = ((x + y) % 360) * 0.01f;
		redraw(all);
	}
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (!all->control.mouse_active)
	{
		return (0);
	}
	if (button == 4)
	{
		all->p.scale++;
	}
	else if (button == 5)
	{
		all->p.scale--;
	}
	redraw(all);
	return (0);
}
