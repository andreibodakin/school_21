/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:03:36 by klavada           #+#    #+#             */
/*   Updated: 2020/05/25 16:38:01 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
