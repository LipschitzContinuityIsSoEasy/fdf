/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:18:32 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:26:41 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
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
//     parametre = '4';
//     printf("%s(%d)", isdigit(parametre) ==
//     ft_isdigit(parametre)? "OK" : "KO", isdigit(parametre));
//     return (0);
// }
