/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 10:59:37 by klavada           #+#    #+#             */
/*   Updated: 2020/05/14 02:06:31 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	result;

	result = 0;
	while (*dst != '\0')
	{
		dst++;
		result++;
	}
	if (result > dstsize)
		result = dstsize;
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
