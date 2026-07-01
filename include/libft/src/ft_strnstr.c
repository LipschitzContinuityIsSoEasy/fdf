/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:45:16 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:39:35 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	j = 0;
	while (i < len && big[i] != '\0')
	{
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
int	main(void)
{
	char parametre1[] = "fgdf";
    char parametre2[] = "";
    int c;

    c = 0;
	printf("%s====\n%s\n",(char *)(strnstr((void *)parametre1, parametre2, c)),
	(char *)(ft_strnstr((void *)parametre1, parametre2, c)));
	return (0);
}
*/