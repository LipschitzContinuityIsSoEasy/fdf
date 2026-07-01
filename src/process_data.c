/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:57 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 18:29:58 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_element(char *element, t_data *data)
{
	char	**sub_split;

	sub_split = ft_split(element, ',');
	if (sub_split != NULL)
	{
		data->z = ft_atoi(sub_split[0]);
		if (sub_split[1] != NULL)
		{
			if (ft_strncmp(sub_split[1], "0x", 2) == 0)
			{
				ft_memmove(sub_split[1], sub_split[1] + 2,
					ft_strlen(sub_split[1]) - 1);
			}
			data->color = ft_atoi_base(sub_split[1], "0123456789abcdef");
		}
		else
		{
			if (data->z > 0)
				data->color = COLOR_Z_POSITIVE;
			else if (data->z < 0)
				data->color = COLOR_Z_NEGATIVE;
		}
		free_tab(sub_split);
	}
}

void	process_row(t_list *current, t_data *array_row, int max_cols)
{
	char	*line;
	char	**split_line;
	int		col;

	line = (char *)current->content;
	split_line = ft_split(line, ' ');
	if (split_line == NULL)
	{
		perror("Failed to split line");
		return ;
	}
	col = 0;
	while (col < max_cols && split_line[col] != NULL)
	{
		process_element(split_line[col], &array_row[col]);
		col++;
	}
	free_tab(split_line);
}

void	convert_data_to_tableau(t_list *l, t_data **array,
			int row_index, int max_cols)
{
	t_list	*current;
	int		row;

	row = 0;
	current = l;
	while (current != NULL && row < row_index)
	{
		process_row(current, array[row], max_cols);
		current = current->next;
		row++;
	}
}

void	process_tableau_data(int *col, int *row, int max_cols, t_data **array)
{
	while (*col < max_cols)
	{
		array[*row][*col].x = *col;
		array[*row][*col].y = *row;
		array[*row][*col].z = 0;
		array[*row][*col].color = COLOR_Z_ZERO;
		(*col)++;
	}
}

int	procces_tableau_row(int row_index, int max_cols, t_data **array)
{
	int	row;
	int	col;

	row = 0;
	while (row < row_index)
	{
		array[row] = (t_data *)malloc(max_cols * sizeof(t_data));
		if (array[row] == NULL)
		{
			while (row > 0)
			{
				free(array[row]);
				row--;
			}
			free(array);
			perror("Failed to allocate memory for array rows");
			return (1);
		}
		col = 0;
		process_tableau_data(&col, &row, max_cols, array);
		row++;
	}
	return (0);
}
