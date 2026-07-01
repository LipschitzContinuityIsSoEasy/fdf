/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meiling <meiling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:32:23 by mtian             #+#    #+#             */
/*   Updated: 2024/08/13 13:26:27 by meiling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != 0)
	{
		i++;
	}
	return (i);
}
// int main(void)
// {
//     const   char *parametre;
//     parametre = "dddzedfkjhqi";
//     printf("%s(%lu)", strlen(parametre) 
//     == ft_strlen(parametre)? "OK" : "KO", strlen(parametre));
//     //printf("%lu",strlen(parametre));
//     return (0);
// }
