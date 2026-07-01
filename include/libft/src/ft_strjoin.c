/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meiling <meiling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:55:32 by mtian             #+#    #+#             */
/*   Updated: 2024/08/13 13:37:10 by meiling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*new_str;
	size_t		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		new_str[i] = s2[i - len1];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
// int	main(void)
// {
// 	char const s1[] = "";
// 	char const s2[] = "";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
