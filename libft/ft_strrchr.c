/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:52:50 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/02 13:52:50 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	len;

	len = ft_strlen(src);
	if (c == 0)
		return ((char *)src + len);
	while (--len >= 0)
		if (src[len] == (char)c)
			return ((char *)src + len);
	return (NULL);
}
