/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:06:04 by klavada           #+#    #+#             */
/*   Updated: 2020/05/20 02:19:15 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s != '\0')
	{
		if (*s++ == (char)c)
			result = ((char *)s - 1);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (result);
}
