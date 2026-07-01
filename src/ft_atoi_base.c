/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:01:20 by mtian             #+#    #+#             */
/*   Updated: 2024/10/15 17:59:09 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_in_base(char c, char *base)
{
	int	position_in_base;

	position_in_base = 0;
	while (base[position_in_base] != '\0')
	{
		if (ft_tolower(c) == base[position_in_base])
		{
			return (position_in_base);
		}
		position_in_base++;
	}
	return (-42);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	signe;
	int	r;
	int	len;

	len = ft_strlen(base);
	signe = 1;
	i = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (ft_in_base(str[i], base) >= 0)
	{
		r = r * len + ft_in_base(str[i], base);
		i++;
	}
	return (r * signe);
}
