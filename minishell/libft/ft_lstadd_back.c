/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:20:31 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/09 11:20:31 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_el;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new_el = ft_lstlast(*lst);
	new_el->next = new;
}
