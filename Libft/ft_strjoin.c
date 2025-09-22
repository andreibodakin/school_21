/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:56:48 by klavada           #+#    #+#             */
/*   Updated: 2020/05/25 18:30:21 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[len])
		len++;
	while (s2[i++])
		len++;
	result = (char*)malloc(len + 1 * sizeof(char*));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}
