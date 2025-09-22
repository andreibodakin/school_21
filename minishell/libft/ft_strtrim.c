/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:31:03 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/03 14:31:03 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	if (set)
	{
		while (*set)
			if (*set++ == c)
				return (1);
	}
	return (0);
}

char		*ft_strtrim(const char *s, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && ft_in_set(s[i], set))
		i++;
	if (*s)
		j = ft_strlen(s) - 1;
	while (j > i && ft_in_set(s[j], set))
		j--;
	if (!(str = (char *)malloc(j - i + 2)))
		return (NULL);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
