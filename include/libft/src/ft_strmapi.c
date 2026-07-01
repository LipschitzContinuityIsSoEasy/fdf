/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:59:32 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:59:49 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_str;
	size_t	true_len;

	true_len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (true_len + 1));
	if (new_str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < true_len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
// char	fff(unsigned int	i, char c)
// {
// 	char	r;

// 	r = c + 1;
// 	return (r);
// }
// int	main(void)
// {
// 	char const s[] = "abcde";
// 	printf("%s\n", ft_strmapi(s, fff));
// 	return (0);
// }
