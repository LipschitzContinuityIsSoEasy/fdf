/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:57:26 by mtian             #+#    #+#             */
/*   Updated: 2024/06/04 18:05:38 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0' && ft_strchr(set, *(s1 + i)))
		i++;
	len = ft_strlen(s1 + i);
	while (len > 0 && ft_strchr(set, s1[i + len - 1]))
		len--;
	return (ft_substr(s1, i, len));
}

/*
int	isdelete(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	true_len;
	size_t	len_s1;
	size_t	i;
	size_t	j;
	size_t	start;

	len_s1 = ft_strlen(s1);
	true_len = 0;
	start = 0;
	i = 0;
	while (s1[i] != '\0' && isdelete(set, s1[i]))
	{
		i++;
	}
	start = i;
	if (start >= len_s1)
		return (ft_strdup(""));
	j = len_s1 - 1;
	while (isdelete(set, s1[j]))
	{
		j--;
	}
	true_len = j - i + 1;
	result = (char *)malloc(sizeof(char) * (true_len + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < true_len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
*/
// int	main(void)
// {
// 	char const s1[] = "(123456 \n";
// 	char const set[] = " \n(";
// 	printf(">%s<\n", ft_strtrim(s1, set));
// 	return (0);
// }
