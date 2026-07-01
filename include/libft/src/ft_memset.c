/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:34:16 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:39:40 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	unsinged_c;
	unsigned char	*pointer;
	size_t			i;

	pointer = (unsigned char *)b;
	unsinged_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*(pointer + i) = unsinged_c;
		i++;
	}
	return (b);
}
// int main(void)
// {
//     char parametre1[] = "www";
//     char parametre2[] = "www";
//     int c;
//     size_t  len;
//     c = 69;
//     len = 1;
//     memset(parametre1, c, len);
//     ft_memset(parametre2, c, len);
//     printf("1: %s\n",parametre1);
//     printf("2: %s\n",parametre2);
//     printf("rewsultat: \n");
//     printf("%d", strcmp(parametre1, parametre2));
//     return (0);
// }
