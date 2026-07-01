/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meiling <meiling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:43:56 by mtian             #+#    #+#             */
/*   Updated: 2024/08/13 13:38:12 by meiling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
// int	main(void)
// {
// 	char parametre1[8] = "1234567";
//     char parametre2[] = "1234567";
// 	char src1[] = "abcde";
// 	char src2[] = "abcde";
// 	int	n;
//     int c;
// 	n = 3;
//     c = '\0';
// 	//toupper(c);
// 	//ft_toupper(c);
// 	printf("%s\n%s\n",strchr(parametre1, c), ft_strchr(parametre1, c));
// 	return (0);
// }
