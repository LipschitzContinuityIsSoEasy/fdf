/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:02:24 by mtian             #+#    #+#             */
/*   Updated: 2024/06/01 18:02:32 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l % 10 != l)
	{
		ft_putnbr_fd(l / 10, fd);
	}
	ft_putchar_fd(l % 10 + 48, fd);
}
// int	main (void)
// {
// 	ft_putnbr_fd(-28464, 1);
// 	return (0);
// }
