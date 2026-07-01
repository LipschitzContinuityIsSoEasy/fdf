/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:14 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:33:25 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_all *all)
{
	mlx_destroy_image(all->mlx, all->img);
	if (all->menu_img != 0)
	{
		mlx_destroy_image(all->mlx, all->menu_img);
	}
	mlx_destroy_window(all->mlx, all->mlx_win);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	free_tab_data(all->tab, all->rows);
	exit (0);
}

void	manage_close(t_all *all)
{
	mlx_hook(all->mlx_win, 2, 1L << 0, key_press, all);
	mlx_hook(all->mlx_win, 3, 1L << 1, key_release, all);
	mlx_hook(all->mlx_win, 6, 1L << 6, mouse_move, all);
	mlx_hook(all->mlx_win, 4, 1L << 2, mouse_scroll, all);
	mlx_hook(all->mlx_win, QUIT, ESC, ft_close, all);
}

void	initialiser_control(t_controls *control)
{
	control->move_left = 0;
	control->move_right = 0;
	control->move_up = 0;
	control->move_down = 0;
	control->smaller = 0;
	control->bigger = 0;
	control->rotation_x = 0;
	control->rotation_y = 0;
	control->rotation_z = 0;
	control->rotation_x_reverse = 0;
	control->rotation_y_reverse = 0;
	control->rotation_z_reverse = 0;
	control->z_plus = 0;
	control->z_moins = 0;
	control->z_defaut = 1;
	control->view_2d_top = 0;
	control->view_2d_front = 0;
	control->view_2d_right = 0;
	control->view_defaut = 1;
	control->color_change = 0;
	control->color_varier_active = 0;
	control->mouse_active = 0;
}

void	initialiser_all(t_all *all)
{
	initialiser_projection(&all->p);
	initialiser_control(&all->control);
	all->color_random = 0;
	all->new_var_z = 0.0f;
	all->plat = set_plat(all->rows);
	apply_controls(all);
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "FDF_Meiling");
	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel,
			&all->line_length, &all->endian);
}

void	fdf(t_all *all)
{
	if (ft_max(all->cols, all->rows) <= 51)
	{
		draw_view_3d(all);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->img,
			MENU_WIDTH, 0);
		load_menu_image(all);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->menu_img, 0, 0);
		manage_close(all);
		mlx_loop_hook(all->mlx, redraw, all);
		mlx_loop(all->mlx);
		free_tab_data(all->tab, all->rows);
	}
	else
	{
		draw_view_3d_v2(all);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->img,
			MENU_WIDTH, 0);
		load_menu_image(all);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->menu_img, 0, 0);
		manage_close(all);
		mlx_loop_hook(all->mlx, redraw_v2, all);
		mlx_loop(all->mlx);
		free_tab_data(all->tab, all->rows);
	}
}
