/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:28:57 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:28:59 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_step(t_bresenham *b, int flag)
{
	if (flag == STEP_HORIZENTAL)
	{
		b->x += b->x_step;
		if (b->p < 0)
			b->p += b->a;
		else
		{
			b->y += b->y_step;
			b->p += b->b;
		}
	}
	else if (flag == STEP_VERTICAL)
	{
		b->y += b->y_step;
		if (b->p < 0)
			b->p += b->a;
		else
		{
			b->x += b->x_step;
			b->p += b->b;
		}
	}
}

void	bresenham_horizontal(t_bresenham *b, t_all *all)
{
	while (b->x != b->scaled_x1)
	{
		if (b->x >= 0 && b->x <= WIDTH && b->y >= 0 && b->y <= HEIGHT)
		{
			b->fraction = calculate_fraction(b->scaled_x0, b->scaled_x1, b->x);
			if (all->control.color_varier_active)
				all->color_random += 10;
			if (all->control.color_change || all->control.color_varier_active)
				b->color = interpolate_color(b->color_start + all->color_random,
						b->color_end + all->color_random, b->fraction);
			else
				b->color = interpolate_color(b->color_start, b->color_end,
						b->fraction);
			b->pixel = all->addr + (b->y * all->line_length + b->x
					* (all->bits_per_pixel / 8));
			*(int *)b->pixel = b->color;
		}
		bresenham_step(b, 0);
	}
}

void	bresenham_vertical(t_bresenham *b, t_all *all)
{
	while (b->y != b->scaled_y1)
	{
		if (b->x >= 0 && b->x <= WIDTH && b->y >= 0 && b->y <= HEIGHT)
		{
			b->fraction = calculate_fraction(b->scaled_y0, b->scaled_y1, b->y);
			if (all->control.color_varier_active)
				all->color_random += 10;
			if (all->control.color_change || all->control.color_varier_active)
				b->color = interpolate_color(b->color_start + all->color_random,
						b->color_end + all->color_random, b->fraction);
			else
				b->color = interpolate_color(b->color_start, b->color_end,
						b->fraction);
			b->pixel = all->addr + (b->y * all->line_length
					+ b->x * (all->bits_per_pixel / 8));
			*(int *)b->pixel = b->color;
		}
		bresenham_step(b, 1);
	}
}

void	bresenham_draw_line(t_bresenham *b, t_all *all,
		t_data *point_0, t_data *point_1)
{
	b->color_start = point_0->color;
	b->color_end = point_1->color;
	b->dx = abs(b->dx);
	b->dy = abs(b->dy);
	if (b->dx >= b->dy)
	{
		b->p = 2 * b->dy - b->dx;
		b->a = 2 * b->dy;
		b->b = 2 * (b->dy - b->dx);
		bresenham_horizontal(b, all);
	}
	else
	{
		b->p = 2 * b->dx - b->dy;
		b->a = 2 * b->dx;
		b->b = 2 * (b->dx - b->dy);
		bresenham_vertical(b, all);
	}
}

void	bresenham(t_data *point_0, t_data *point_1, t_all *all)
{
	t_bresenham	b;

	b.scaled_x0 = point_0->x;
	b.scaled_y0 = point_0->y;
	b.scaled_x1 = point_1->x;
	b.scaled_y1 = point_1->y;
	b.dy = b.scaled_y1 - b.scaled_y0;
	b.dx = b.scaled_x1 - b.scaled_x0;
	b.x = b.scaled_x0;
	b.y = b.scaled_y0;
	if (b.dx > 0)
		b.x_step = 1;
	else
		b.x_step = -1;
	if (b.dy > 0)
		b.y_step = 1;
	else
		b.y_step = -1;
	bresenham_draw_line(&b, all, point_0, point_1);
}
