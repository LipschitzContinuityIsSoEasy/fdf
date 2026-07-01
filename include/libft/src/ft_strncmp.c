/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:45:32 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:46:57 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
// 	printf("%d, %d\n", ft_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
// 	printf("%d, %d\n", ft_strncmp(s1, s2, 2), strncmp(s1, s2, 2));
// 	printf("%d, %d\n", ft_strncmp(s3, s4, 4), strncmp(s3, s4, 4));
// 	printf("%d, %d\n", ft_strncmp(s3, s4, 1), strncmp(s3, s4, 1));
// 	printf("%d, %d\n", ft_strncmp(s5, s6, 3), strncmp(s5, s6, 3));
// 	printf("%d, %d\n", ft_strncmp(s5, s5, 10), strncmp(s5, s5, 10));
// 	printf("%d, %d\n", ft_strncmp(s5, s5, 5), strncmp(s5, s5, 5));
// 	printf("%d, %d\n", ft_strncmp(s5, s7, 7), strncmp(s5, s7, 7));
// 	printf("%d, %d\n", ft_strncmp(s5, s7, 8), strncmp(s5, s7, 8));
// 	printf("%d, %d\n", ft_strncmp(s8, s1, 8), strncmp(s8, s1, 8));
// 	printf("%d, %d\n", ft_strncmp(s8, s9, 2), strncmp(s8, s9, 2));
// 	//printf("%d, %d\n", ft_strncmp(s1, s2, 0), strncmp(s1, s2, 0));
// }
