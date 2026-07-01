/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:34:28 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 17:38:31 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = len;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char parametre1[40] = "123abcd6 7";
//     char parametre2[] = "1234567";
// 	char src1[] = "abcde";
// 	char src2[] = "abcde";
// 	int	n;
//     int c;
// 	n = 3;
//     c = 'e';
// 	//toupper(c);
// 	//ft_toupper(c);
// 	printf("%s     %s",strrchr(parametre1, c), ft_strrchr(parametre1, c));
// 	return (0);
// }
