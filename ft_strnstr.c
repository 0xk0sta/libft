/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:16:22 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/17 18:11:50 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len && haystack[i])
	{
		o = 0;
		while (haystack[i + o] != '\0' && haystack[i + o] == needle[o]
			&& len - o > 0)
		{
			if (needle[o + 1] == '\0')
				return ((char *)&haystack[i]);
			o++;
		}
		len--;
		i++;
	}
	return (NULL);
}
