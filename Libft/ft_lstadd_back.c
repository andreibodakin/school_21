/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 04:32:22 by klavada           #+#    #+#             */
/*   Updated: 2020/05/27 06:17:55 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *new_node;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new_node = ft_lstlast(*lst);
	new_node->next = new;
}
