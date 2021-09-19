/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:42:28 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/18 02:57:32 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*int_to_char(char *str, int n, int n_len)
{
	while (n)
	{
		str[n_len--] = (n % 10) + '0';
		 n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		n_len;

	n_len = int_len(n);
	str = malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (0);
	str[n_len--] = '\0';
	if (n == -2147483648)
	{
		str[n_len--] = '8';
		n = -214748364;
	}
	if (n == 0)
	{
		str[n_len] = '0';
		return (str);
	}
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str = int_to_char(str, n, n_len);
	return (str);
}
//
//int main()
//{
//	printf("%s\n", ft_itoa(-2147483648));
//}
