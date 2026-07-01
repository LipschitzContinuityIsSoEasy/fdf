/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:44:20 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:44:34 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}
// meiling
// int	main(void)
// {
// 	int	*a = (int *)malloc(sizeof(int));
// 	if (a == NULL)
// 	{
// 		return (1);
// 	}
// 	*a = 10;
// 	t_list	*n1;
// 	n1 = ft_lstnew(a);
// 	if (n1 == NULL)
// 	{
// 		free(a);
// 		return (1);
// 	}

// 	char *c = (char *)malloc(sizeof(char));
// 	if (c ==NULL)
// 	{
// 		free(a);
// 		free(n1);
// 		return (1);
// 	}

// 	*c = 'a';
// 	t_list	*n2;
// 	n2 = ft_lstnew(c);
// 	if (n2 == NULL)
// 	{
// 		free(a);
// 		free(c);
// 		free(n1);
// 		return (1);
// 	}

// 	t_list	*l;

// 	l = NULL;
// 	ft_lstadd_front(&l, n2);
// 	ft_lstadd_front(&l, n1);
// 	t_list	*current;

// 	current = l;
// 	while (current != NULL)
// 	{
// 		printf("%d\n", *(int *)(current->content));
// 		current = current->next;
// 	}
// 	printf("%s\n", "==================");

// 	float	*b;
// 	b = (float *)malloc(sizeof(float));
// 	if (b == NULL)
// 	{
// 		free(a);
// 		free(c);
// 		free(n1);
// 		free(n2);
// 		return (1);
// 	}
// 	*b = 34.5;
// 	t_list	*n0;
// 	n0 = ft_lstnew(b);
// 	if (n0 == NULL)
// 	{
// 		free(a);
// 		free(c);
// 		free(n1);
// 		free(n2);
// 		free(b);
// 		return (1);
// 	}
// 	ft_lstadd_front(&l, n0);

// 	current = l;
// 	while (current != NULL)
// 	{
// 		printf("%d\n", *(int *)(current->content));
// 		current = current->next;
// 	}

// 	free(a);
// 	free(c);
// 	free(b);
// 	free(n1);
// 	free(n2);
// 	free(n0);

// 	return (0);
// }
