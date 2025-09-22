/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:55:35 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/25 11:21:31 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	length = ft_strlen(s + start);
	if (length < len)
		len = length;
	if (!(str = (char *)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (len > 0)
	{
		str[len - 1] = s[start + len - 1];
		len--;
	}
	return (str);
}
