/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:34:45 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/15 11:12:26 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (NULL);
	if (s < d)
	{
		d += len;
		s += len;
		while (len--)
			*(unsigned char *)--d = *(unsigned char *)--s;
	}
	else
	{
		while (len--)
		{
			*(unsigned char *)d = *(unsigned char *)s;
			d++;
			s++;
		}
	}
	return (dst);
}
