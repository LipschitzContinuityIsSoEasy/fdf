/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:55:27 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:56:37 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n;
	void	*result;

	if (lst != NULL && f != NULL
		&& del != NULL)
	{
		new = NULL;
		while (lst != NULL)
		{
			result = f(lst->content);
			n = ft_lstnew(result);
			if (n == NULL)
			{
				del(result);
				ft_lstclear(&new, del);
				return (NULL);
			}
			ft_lstadd_back(&new, n);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
