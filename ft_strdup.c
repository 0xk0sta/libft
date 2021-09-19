/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:04:41 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/15 10:15:29 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		size;

	size = ft_strlen(src);
	dst = malloc((sizeof(char) * size) + 1);
	if (dst == NULL)
		return (0);
	return (ft_strcpy(dst, src));
}
