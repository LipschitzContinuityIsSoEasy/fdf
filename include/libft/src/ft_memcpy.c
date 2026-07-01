/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:41:28 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 14:26:06 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pointer_dst;
	unsigned char	*pointer_src;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	pointer_dst = (unsigned char *)dst;
	pointer_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pointer_dst[i] = pointer_src[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char parametre1[] = "1234567";
//     char parametre2[] = "1234567";
// 	char src1[] = "abcde";
// 	char src2[] = "abcde";
// 	int	n;

// 	n = 3;
// 	memcpy(parametre1, src1, n);
// 	ft_memcpy(parametre2, src2, n);
// 	printf("%d", strcmp(parametre1, parametre2));
// 	return (0);
// }
