/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:48:18 by mtian             #+#    #+#             */
/*   Updated: 2024/07/19 18:49:58 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}
// int main(void)
// {
//     int *a;
//     char    *c;
//     int *e;
//     t_list  *n_a;
//     t_list  *n_c;
//     t_list  *n_e;

//     a = (int *)malloc(sizeof(int));
//     c = (char *)malloc(sizeof(char));
//     e = (int *)malloc(sizeof(int));

//     *a = 5;
//     *c = 'a';
//     *e = 78;

//     n_a = ft_lstnew(a);
//     n_c = ft_lstnew(c);
//     n_e = ft_lstnew(e);

//     t_list  *l;

//     l = NULL;

//     ft_lstadd_back(&l, n_a);
//     ft_lstadd_back(&l, n_c);
//     ft_lstadd_back(&l, n_e);

//     t_list  *current;
//     current = l;
//     while (current != NULL)
//     {
//         printf("%d\n", *(int *)current->content);
//         current = current->next;
//     }
//     return (0);
// }
