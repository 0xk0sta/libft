/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:45:34 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/15 16:33:48 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset_check(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*c;
	unsigned int	j;	
	unsigned int	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (charset_check(s1[i], set) == 1)
		i++;
	if (i == j)
	{
		c = ft_strdup("");
		if (!c)
			return (NULL);
		else
			return (c);
	}
	while (charset_check(s1[j - 1], set) == 1)
		j--;
	c = ft_substr(s1, i, j - i);
	return (c);
}
