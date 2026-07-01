/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:43:07 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:44:06 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	{
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
// int	main(void)
// {
// 	int *a = (int *)malloc(sizeof(int) * 1);
// 	*a = 10;
// 	t_list *n1 = ft_lstnew(a);
// 	if (n1 != NULL)
// 	{
// 		printf("%d\n", *(int *)(n1->content));
// 	}
// 	float *b = (float *)malloc(sizeof(float) * 1);
// 	*b = 10.34;
// 	t_list *n2 = ft_lstnew(b);
// 	n1->next = n2;
// 	if (n2 != NULL)
// 	{
// 		printf("%f\n", *(float *)(n2->content));
// 	}
// 	free(a);
// 	free(b);
// 	free(n1);
// 	free(n2);
// 	return (0);
// }
