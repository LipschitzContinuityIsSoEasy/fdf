/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:11 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:11 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_true_line(t_map *map, int line_direction, int map_size, t_all *all)
{
	if (line_direction == LINE_DIRECTION_RIGHT && map_size == SMALL_MAP)
	{
		map->iso_point_right = isometric(*map->point_right, &all->p, *all);
		bresenham(&map->iso_point, &map->iso_point_right, all);
	}
	else if (line_direction == LINE_DIRECTION_DOWN && map_size == SMALL_MAP)
	{
		map->iso_point_down = isometric(*map->point_down, &all->p, *all);
		bresenham(&map->iso_point, &map->iso_point_down, all);
	}
	else if (line_direction == LINE_DIRECTION_RIGHT && map_size == BIG_MAP)
	{
		map->iso_point_right = isometric_v2(*map->point_right, &all->p, *all);
		bresenham(&map->iso_point, &map->iso_point_right, all);
	}
	else if (line_direction == LINE_DIRECTION_DOWN && map_size == BIG_MAP)
	{
		map->iso_point_down = isometric_v2(*map->point_down, &all->p, *all);
		bresenham(&map->iso_point, &map->iso_point_down, all);
	}
}

void	draw_view_3d(t_all *all)
{
	int		row;
	int		col;
	t_map	map;

	row = 0;
	while (row < all->rows)
	{
		col = 0;
		while (col < all->cols)
		{
			map.point = &all->tab[row][col];
			map.iso_point = isometric(*map.point, &all->p, *all);
			map.point_right = find_point_right(all->tab, row, col, all->cols);
			if (map.point_right != NULL)
				draw_true_line(&map, 0, 0, all);
			map.point_down = find_point_down(all->tab, row, col, all->rows);
			if (map.point_down != NULL)
				draw_true_line(&map, 1, 0, all);
			col++;
		}
		row++;
	}
}

void	draw_view_3d_v2(t_all *all)
{
	int		row;
	int		col;
	t_map	map;

	row = 0;
	while (row < all->rows)
	{
		col = 0;
		while (col < all->cols)
		{
			map.point = &all->tab[row][col];
			map.iso_point = isometric_v2(*map.point, &all->p, *all);
			map.point_right = find_point_right(all->tab, row, col, all->cols);
			if (map.point_right != NULL)
				draw_true_line(&map, 0, 1, all);
			map.point_down = find_point_down(all->tab, row, col, all->rows);
			if (map.point_down != NULL)
				draw_true_line(&map, 1, 1, all);
			col++;
		}
		row++;
	}
}

int	redraw(void *params)
{
	t_all	*all;

	all = (t_all *)params;
	mlx_destroy_image(all->mlx, all->img);
	apply_controls(all);
	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel,
			&all->line_length, &all->endian);
	draw_view_3d(all);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img, MENU_WIDTH, 0);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->menu_img, 0, 0);
	return (0);
}

int	redraw_v2(void *params)
{
	t_all	*all;

	all = (t_all *)params;
	mlx_destroy_image(all->mlx, all->img);
	apply_controls(all);
	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel,
			&all->line_length, &all->endian);
	draw_view_3d_v2(all);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img, MENU_WIDTH, 0);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->menu_img, 0, 0);
	return (0);
}
