/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:39:51 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:41:06 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*unsigned_s;

	i = 0;
	unsigned_s = (unsigned char *)s;
	while (i < n)
	{
		unsigned_s[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char parametre1[] = "1234567";
    char parametre2[] = "1234567";
	int	size;

	size = 3;
	bzero(parametre1, size);
	ft_bzero(parametre2, size);
	printf("%c\n", parametre1[5]);
	printf("%d", strcmp(parametre1, parametre2));


	write(1, "\n", 1);
	write(1, parametre1, 7);
	write(1, "\n", 1);
	write(1, &(parametre1[6]), 1);
	write(1, "\n", 1);
	write(1, &(parametre1[7]), 1);
	return (0);
}
*/
