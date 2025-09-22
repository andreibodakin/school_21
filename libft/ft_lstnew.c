/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:59:05 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/08 13:59:05 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	if (!(new_el = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
