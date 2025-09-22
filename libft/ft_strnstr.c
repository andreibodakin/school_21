/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:56:51 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/02 14:56:51 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(small);
	if (len_s == 0)
		return ((char *)big);
	while (big[i] && len_s <= len--)
	{
		if (ft_strncmp(small, big + i, len_s) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
