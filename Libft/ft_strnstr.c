/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:40:12 by klavada           #+#    #+#             */
/*   Updated: 2020/05/27 23:50:43 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t nee_len;
	size_t i;

	i = 0;
	nee_len = ft_strlen(nee);
	if (nee_len == 0)
		return ((char *)hay);
	while (hay[i] && nee_len <= len--)
	{
		if (ft_strncmp(nee, hay + i, nee_len) == 0)
			return ((char *)hay + i);
		i++;
	}
	return (NULL);
}
