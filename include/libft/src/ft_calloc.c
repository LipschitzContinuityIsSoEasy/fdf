/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:59:12 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 18:00:34 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;
	size_t			len;

	if (count != 0 && size > INT_MAX / count)
	{
		return (NULL);
	}
	len = count * size;
	str = (unsigned char *)malloc(len);
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*mem;

// 	if (nmemb > SIZE_MAX / size)
// 		return (NULL);
// 	mem = malloc (nmemb * size);
// 	if (!mem)
// 		return (NULL);
// 	ft_bzero(mem, (nmemb * size));
// 	return (mem);
// }

// int	main(void)
// {
// 	size_t	count;

// 	count = 5;
// 	printf(">%s<\n>%s<\n", (char *)calloc(5, sizeof(char)),
// 	(char *)ft_calloc(5, sizeof(char)));
// 	//char *t = (char *)ft_calloc(5, sizeof(char));
// 	//t[10] = 'v';
// 	//printf("%c\n", t[10]);
// 	return (0);
// }
