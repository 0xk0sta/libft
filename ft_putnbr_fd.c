/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:51:10 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/17 18:11:31 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		divisor;
	long	r;

	r = n;
	divisor = 1000000000;
	if (r < 0)
	{
		ft_write('-', fd);
		r *= -1;
	}
	if (r == 0)
		ft_write('0', fd);
	else
	{
		while (!(r / divisor))
			divisor = divisor / 10;
		while (divisor > 0 )
		{
			ft_write(r / divisor + '0', fd);
			r %= divisor;
			divisor = divisor / 10;
		}
	}
}
