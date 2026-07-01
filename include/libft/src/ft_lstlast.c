/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:46:23 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:48:01 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
//un peu corriger par gpt
//juste oublie *b = 'a';
// int main(void)
// {
//     int *a;
//     char *b;
//     a = (int *)malloc(sizeof(int));
//     if (a == NULL)
//     {
//         return (1);
//     }
//     *a = 4;
//     b = (char *)malloc(sizeof(char));
//     if (b == NULL)
//     {
//         free(a);
//         return (1);
//     }

// 	*b ='a';
//     t_list  *n2;
//     t_list  *n1;
//     n2 = ft_lstnew(b);
//     if (n2 == NULL)
//     {
//         free(a);
//         free(b);
//         return (1);
//     }

//     n1 = ft_lstnew(a);
//     if (n1 == NULL)
//     {
//         free(a);
//         free(b);
//         free(n2);
//         return (1);
//     }

//     t_list  *lst;
//     lst = NULL;
//     ft_lstadd_front(&lst, n2);
//     ft_lstadd_front(&lst, n1);

//     t_list *last_node = ft_lstlast(lst);
//     if (last_node != NULL)
//     {
//         printf("The content of the last node is: %s\n",
//         (char *)last_node->content);
//     }
//     else
//     {
//         printf("The list is empty.\n");
//     }

//     free(a);
//     free(b);
//     free(n1);
//     free(n2);
//     return (0);
// }

// int	main(void)
// {
// 	int	*a;
// 	char *b;

// 	a = (int *)malloc(sizeof(int));
// 	if (a == NULL)
// 	{
// 		return (1);
// 	}
// 	*a = 4;

// 	b = (char *)malloc(sizeof(char));
// 	if (b == NULL)
// 	{
// 		free(a);
// 		return (1);
// 	}
// 	*b = 'a';
// 	t_list	*n2;
// 	t_list	*n1;
// 	n2 = ft_lstnew(b);
// 	if (n2 == NULL)
// 	{
// 		free(a);
// 		free(b);
// 		return (1);
// 	}

// 	n1 = ft_lstnew(a);
// 	if (n1 == NULL)
// 	{
// 		free(a);
// 		free(b);
// 		free(n2);
// 		return (1);
// 	}

// 	t_list/a/	*lst;
// 	lst = NULL;
// 	ft_lstadd_front(&lst, n2);
// 	ft_lstadd_front(&lst, n1);

// 	printf("%s\n", (char *)ft_lstlast(lst)->content);

// 	free(a);
// 	free(b);
// 	free(n1);
// 	free(n2);
// 	return (0);
// }
