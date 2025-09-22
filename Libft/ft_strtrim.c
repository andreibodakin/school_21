/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 20:28:03 by klavada           #+#    #+#             */
/*   Updated: 2020/05/27 08:20:06 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char*)s1);
	len = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1)
		len = ft_strlen(s1) - 1;
	while (*s1 && len && ft_strrchr(set, s1[len]))
		len--;
	result = ft_substr(s1, 0, len + 1);
	return (result);
}
