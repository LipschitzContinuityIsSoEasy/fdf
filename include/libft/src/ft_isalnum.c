/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:26:56 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:30:22 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// int main(void)
// {
//     int parametre;
//     parametre = ' ';
//     printf("%s(%d)", isalnum(parametre) ==
//     ft_isalnum(parametre)? "OK" : "KO", isalnum(parametre));
//     return (0);
// }
