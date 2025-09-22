/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:28:44 by klavada           #+#    #+#             */
/*   Updated: 2020/05/26 04:25:14 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*s_sub;
	size_t		s_len;
	size_t		i;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start > s_len)
		len = 0;
	if ((s_len - start) < len)
		len = s_len - start;
	s_sub = (char *)malloc((sizeof(char)) * (len + 1));
	if (!s_sub)
		return (NULL);
	i = 0;
	while (i < len && *s)
	{
		s_sub[i] = s[start + i];
		i++;
	}
	s_sub[i] = '\0';
	return (s_sub);
}
