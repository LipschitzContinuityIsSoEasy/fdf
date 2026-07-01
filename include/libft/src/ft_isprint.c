/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:31:31 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 17:32:08 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
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
//     parametre = '\n';
//     printf("%s(%d)", isprint(parametre) 
//     == ft_isprint(parametre)? "OK" : "KO", isprint(parametre));
//     return (0);
// }
