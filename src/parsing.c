/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:29:54 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 19:01:05 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	**malloc_tableau_2_dimension(int row_index, int max_cols)
{
	t_data	**array;

	array = (t_data **)malloc(row_index * sizeof(t_data *));
	if (array == NULL)
	{
		perror("Failed to allocate memory for array rows");
		return (NULL);
	}
	if (procces_tableau_row(row_index, max_cols, array) == 1)
	{
		return (NULL);
	}
	return (array);
}

t_data	**list_to_2d_array(t_list *l, int row_index, int max_cols)
{
	t_data	**array;

	array = malloc_tableau_2_dimension(row_index, max_cols);
	if (array == NULL)
	{
		return (array);
	}
	convert_data_to_tableau(l, array, row_index, max_cols);
	return (array);
}

void	process_spaced_line(char *line, t_list **l, int *max_cols)
{
	char	*line_data;
	char	**split_line;
	int		col_count;
	t_list	*node;

	col_count = 0;
	line_data = ft_strdup(line);
	if (line_data == NULL)
	{
		free(line);
		print_error_exit(l);
	}
	split_line = ft_split(line, ' ');
	while (split_line[col_count] != NULL)
		col_count++;
	free_tab(split_line);
	if (*max_cols < col_count)
		*max_cols = col_count;
	node = ft_lstnew(line_data);
	if (node == NULL)
	{
		free(line_data);
		print_error_exit(l);
	}
	ft_lstadd_back(l, node);
}

void	parse_file_to_list(char *file_name, t_list **l,
			int *row_index, int *max_cols)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		clear_list(l);
		perror("Error opening file");
		exit(1);
	}
	*row_index = 0;
	*max_cols = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		process_spaced_line(line, l, max_cols);
		free(line);
		line = get_next_line(fd, 0);
		(*row_index)++;
	}
	close(fd);
}
