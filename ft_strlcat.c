/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:35:19 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/18 00:46:28 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src,
		size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	dst_len_og;

	i = 0;
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dst_len_og = ft_strlen(dest);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len_og)
		return (src_len + dstsize);
	while (dst_len < dstsize - 1 && src[i] != '\0')
	{
		dest[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dest[dst_len] = '\0';
	return (dst_len_og + src_len);
}
