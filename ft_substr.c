/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:23:18 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/18 00:58:51 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	new_str = malloc((sizeof(char) * len) + 1);
	if (start > ft_strlen(s))
	{
		*new_str = 0;
		return (new_str);
	}
	if (new_str == NULL)
		return (NULL);
	if (start <= ft_strlen(s))
		ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}
