/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:17:27 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/02 12:17:27 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	len_s;
	size_t	len_add;

	len_s = ft_strlen(src);
	len_add = 0;
	while (*dest && len > 0)
	{
		len_add++;
		len--;
		dest++;
	}
	if (len != 0)
	{
		while (*src && len-- > 1)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (len_s + len_add);
}
