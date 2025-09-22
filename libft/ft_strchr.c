/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:27:13 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/02 13:27:13 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return ((char *)src + ft_strlen(src));
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
