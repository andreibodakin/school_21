/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:21:54 by klavada           #+#    #+#             */
/*   Updated: 2020/05/24 03:25:50 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t result;

	result = 0;
	if (dst == NULL || src == NULL)
		return (result);
	while (*src != '\0')
	{
		if ((result < dstsize - 1) && dstsize != 0)
			*dst++ = *src++;
		else
			src++;
		result++;
	}
	if (dstsize != 0)
		*dst++ = '\0';
	return (result);
}
