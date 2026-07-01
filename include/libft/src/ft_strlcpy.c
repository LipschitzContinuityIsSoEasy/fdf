/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:27:29 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:29:18 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(src);
	if (size == 0)
	{
		return (dst_len);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst_len);
}
/*
int main() {
    char src[] = "Hello, World!";
    char dst1[20];
    char dst2[20];
    size_t size1, size2;

    size1 = strlcpy(dst1, src, sizeof(dst1));
    printf("strlcpy:\n");
    printf("  Source: %s\n", src);
    printf("  Dest %s\n", dst1);
    printf("  len %zu\n", size1);

    size2 = ft_strlcpy(dst2, src, sizeof(dst2));
    printf("ft_strlcpy:\n");
    printf("  Source: %s\n", src);
    printf("  Dest %s\n", dst2);
    printf("  len %zu\n", size2);

    if (size1 == size2 && strcmp(dst1, dst2) == 0) {
        printf("good\n");
    } else {
        printf("not good\n");
    }

    return 0;
}
*/
