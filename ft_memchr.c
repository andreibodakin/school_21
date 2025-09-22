/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:08:12 by klavada           #+#    #+#             */
/*   Updated: 2020/05/24 06:28:15 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	result = (unsigned char *)s;
	while (i < n)
	{
		if (result[i] != (unsigned char)c)
			i++;
		else
			return (&result[i]);
	}
	return (NULL);
}
