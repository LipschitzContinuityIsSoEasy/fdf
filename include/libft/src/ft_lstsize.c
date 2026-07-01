/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:45:16 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:45:44 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// int	main(void)
// {
// 	int	len;
// 	int	*a;
// 	char	*b;
// 	t_list	*n2;
// 	t_list	*n1;
// 	t_list	*lst;
// 	a = (int *)malloc(sizeof(int));
// 	if (a == NULL)
// 	{
// 		return (1);
// 	}
// 	b = (char *)malloc(sizeof(char));
// 	if (b == NULL)
// 	{
// 		free(a);
// 		return (1);
// 	}
// 	*a = 2;
// 	*b = 'i';
// 	n2 = ft_lstnew(a);
// 	if (n2 == NULL)
// 	{
// 		free(a);
// 		free(b);
// 		return (1);
// 	}
// 	n1 = ft_lstnew(b);
// 	if (n1 == NULL)
// 	{
// 		free(a);
// 		free(b);
// 		free(n2);
// 	}
// 	lst = NULL;
// 	ft_lstadd_front(&lst, n2);
// 	ft_lstadd_front(&lst, n1);
// 	len = ft_lstsize(lst);
// 	printf("%d\n", len);
// 	free(a);
// 	free(b);
// 	free(n1);
// 	free(n2);
// 	return (0);
// }
