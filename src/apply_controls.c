/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:28:50 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:28:52 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_controls(t_all *all)
{
	apply_controls_move(all);
	apply_controls_scale(all);
	apply_controls_rotation(all);
	apply_controls_height(all);
	apply_controls_color(all);
}
