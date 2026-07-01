/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:26:06 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:27:06 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
printf("\n\n\tdst[%p]:	%s\n\tsrc[%p]:	%s\n\n",
	dst, (char *)dst, src, (char *)src);
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	char	dst[10] = "fffffffff";
	char	dst_ft[10] = "fffffffff";
	(void)ac;

	char 	*ptr = memmove(dst, av[1], 5);
	char 	*ptr_ft = ft_memmove(dst_ft, av[1], 5);

	printf("first:\n");
	printf("memmove[%p]	:	%s\n", ptr, ptr);
	printf("ft_memmove[%p]	:	%s\n", ptr_ft, ptr_ft);

	ptr = memmove(dst, dst + 2, 2);
	ptr_ft = ft_memmove(dst_ft, dst_ft + 2, 2);

	printf("second:\n");
	printf("memmove[%p]	:	%s\n", ptr, ptr);
	printf("ft_memmove[%p]	:	%s\n", ptr_ft, ptr_ft);
	return (0);
}
*/
// void *ft_memmove(void *dst, const void *src, unsigned long len)
// {
// 	unsigned long	i;
// 	unsigned    char *pointer_dst;
// 	unsigned    char *pointer_src;
// 	char	c;

// 	if (dst == NULL || src == NULL)
// 	{
// 		return (NULL);
// 	}
// 	pointer_dst = (unsigned char *)dst;
// 	pointer_src = (unsigned char *)src;
// 	c = '\0';
// 	i = 0;
// 	while (i < len)
// 	{
// 		pointer_dst[i] = pointer_src[i];
// 		i++;
// 	}
// 	return (dst);
// }
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
