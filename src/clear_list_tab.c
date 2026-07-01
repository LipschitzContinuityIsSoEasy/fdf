/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:02 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:03 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_list(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		temp = current->next;
		free(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}

void	free_tab_data(t_data **tab, int row_index)
{
	int	row;

	row = 0;
	while (row < row_index)
	{
		free(tab[row]);
		row++;
	}
	free(tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	print_error_exit(t_list **l)
{
	write (2, "Error\n", 6);
	if (l != NULL && *l != NULL)
	{
		clear_list(l);
	}
	exit(1);
}
