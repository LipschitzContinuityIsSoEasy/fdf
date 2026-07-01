/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:18 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:19 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*find_point_right(t_data **tableau, int row, int col, int max_cols)
{
	if (col + 1 >= max_cols)
	{
		return (NULL);
	}
	return (&(tableau[row][col + 1]));
}

t_data	*find_point_down(t_data **tableau, int row, int col, int row_index)
{
	if (row + 1 >= row_index)
	{
		return (NULL);
	}
	return (&(tableau[row + 1][col]));
}
