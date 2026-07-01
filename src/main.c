/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:46 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:33:10 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fdf map_file", 2);
		return (1);
	}
	all.l = NULL;
	parse_file_to_list(argv[1], &all.l, &all.rows, &all.cols);
	all.tab = list_to_2d_array(all.l, all.rows, all.cols);
	if (all.tab == NULL)
	{
		clear_list(&all.l);
		return (0);
	}
	clear_list(&all.l);
	initialiser_all(&all);
	fdf(&all);
	return (0);
}
