/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:50:14 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:51:46 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && unsigned_s1[i] == unsigned_s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (unsigned_s1[i] - unsigned_s2[i]);
}
// int	main(void)
// {
// 	char s1[] = "Test1";
// 	char s2[] = "OK";
// 	char s3[] = "Same";
// 	char s4[] = "Size";
// 	char s5[] = "Shorter";
// 	char s6[] = "ThanMyself";
// 	char s7[] = "ShorterTest";
// 	char s8[] = "";
// 	char s9[] = "";
// 	printf("%d, %d\n", ft_memcmp(s1, s2, 4), memcmp(s1, s2, 4));
// 	printf("%d, %d\n", ft_memcmp(s1, s2, 2), memcmp(s1, s2, 2));
// 	printf("%d, %d\n", ft_memcmp(s3, s4, 4), memcmp(s3, s4, 4));
// 	printf("%d, %d\n", ft_memcmp(s3, s4, 1), memcmp(s3, s4, 1));
// 	printf("%d, %d\n", ft_memcmp(s5, s6, 3), memcmp(s5, s6, 3));
// 	printf("%d, %d\n", ft_memcmp(s5, s5, 10), memcmp(s5, s5, 10));
// 	printf("%d, %d\n", ft_memcmp(s5, s5, 5), memcmp(s5, s5, 5));
// 	printf("%d, %d\n", ft_memcmp(s5, s7, 7), memcmp(s5, s7, 7));
// 	printf("%d, %d\n", ft_memcmp(s5, s7, 8), memcmp(s5, s7, 8));
// 	printf("%d, %d\n", ft_memcmp(s8, s1, 8), memcmp(s8, s1, 8));
// 	printf("%d, %d\n", ft_memcmp(s8, s9, 2), memcmp(s8, s9, 2));
// 	//printf("%d, %d\n", ft_strncmp(s1, s2, 0), strncmp(s1, s2, 0));
// }
