/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:31:48 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/17 18:41:18 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char *s, char c)
{
	int	t_words;

	t_words = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		t_words++;
		while (*s == c && *s)
			s++;
	}
	return (t_words);
}

static int	chr_cnt(char *s, char c)
{
	int	total;

	total = 0;
	while (*s != c && *s++)
		total++;
	return (total);
}

static int	tab_filler(char **tab, char *s, char c, int totalw)
{
	int	i;
	int	o;
	int	split_len;

	o = -1;
	while (++o < totalw)
	{
		i = 0;
		split_len = chr_cnt(s, c);
		tab[o] = (char *)malloc(sizeof(char) * (split_len + 1));
		if (!tab[o])
		{
			while (--o >= 0)
				free(tab[o]);
			free(tab);
			return (1);
		}
		while (*s != c && *s)
			tab[o][i++] = *s++;
		tab[o][i] = '\0';
		while (*s == c && *s)
			s++;
	}
	tab[totalw] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		totalw;
	char	*tmp_str;
	char	**tab;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	tmp_str = ft_strtrim(s, &c);
	if (!tmp_str)
		return (NULL);
	totalw = word_cnt(tmp_str, c);
	tab = (char **)malloc(sizeof(char *) * (totalw + 1));
	if (!tab)
	{
		free(tmp_str);
		return (NULL);
	}
	if (tab_filler(tab, tmp_str, c, totalw))
	{
		free(tmp_str);
		return (NULL);
	}
	free(tmp_str);
	return (tab);
}
