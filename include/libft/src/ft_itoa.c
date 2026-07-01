/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:58:40 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:59:18 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countnbr(int n)
{
	long	l;
	size_t	count_nb;

	l = n;
	count_nb = 1;
	if (l < 0)
	{
		l = -l;
		count_nb = count_nb + 1;
	}
	while (l % 10 != l)
	{
		l = l / 10;
		count_nb++;
	}
	return (count_nb);
}

static void	ft_putnbr_decimal(int n, char *result, size_t i)
{
	long	l;

	l = n;
	if (l < 0)
	{
		result[0] = ('-');
		l = -l;
	}
	if (l % 10 != l)
	{
		ft_putnbr_decimal(l / 10, result, i - 1);
	}
	result[i] = l % 10 + 48;
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	true_len;

	true_len = ft_countnbr(n);
	result = (char *)malloc(sizeof(char) * (true_len + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	ft_putnbr_decimal(n, result, true_len - 1);
	result[true_len] = '\0';
	return (result);
}
/*
int	main(void)
{
	printf("%zu\n", ft_countnbr(-91234));
	return (0);
}
*/
// int main(void)
// {
//     char *str = ft_itoa(-91234);
// 	printf("%zu\n", ft_countnbr(-91234));
//     printf("%s\n", str);
//     free(str);  // Don't forget to free the allocated memory
//     return (0);
// }
