/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:30:09 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:30:09 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_max(int a, int b)
{
	if (a >= b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

float	set_plat(int rows)
{
	if (rows == 500)
		return (18.0f);
	else if (rows == 116)
		return (9.0f);
	else if (rows == 200)
		return (90.0f);
	else if (rows == 37)
		return (2.0f);
	else
		return (0.0f);
}

void	load_menu_image(t_all *all)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	if (ft_max(all->cols, all->rows) <= 51)
	{
		relative_path = "./menu_xpm/menu1.xpm";
	}
	else
	{
		relative_path = "./menu_xpm/menu2.xpm";
	}
	all->menu_img = mlx_xpm_file_to_image(all->mlx, relative_path,
			&img_width, &img_height);
	if (!all->menu_img)
	{
		return ;
	}
}
