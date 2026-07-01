/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:29:28 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:29:34 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (src_len + size);
	}
	i = 0;
	while (i < size - dst_len - 1 && src[i])
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	*(dst + dst_len + i) = 0;
	return (src_len + dst_len);
}
/*
#include<stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	dst[10] = "hel";
	char	dst_ft[10] = "hel";
	size_t	result;
	size_t	result_ft;

	(void)ac;

	result = strlcat(dst, av[1], ft_atoi(av[2]));
	result_ft = ft_strlcat(dst_ft, av[1], ft_atoi(av[2]));

	printf("strlcat		:%s(%zu)\n", dst, result);
	printf("ft_strlcat	:%s(%zu)\n", dst_ft, result_ft);
	// while (1);
	return (0);
}
*/
