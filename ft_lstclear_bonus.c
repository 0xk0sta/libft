/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:53:24 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/17 15:53:53 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*previous;

	if (!lst)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		previous = *lst;
		(*lst) = (*lst)->next;
		free(previous);
	}
	(*lst) = NULL;
}
