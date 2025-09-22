/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 04:25:54 by klavada           #+#    #+#             */
/*   Updated: 2020/05/28 16:48:49 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_len(const char *str, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i++])
		len++;
	return (len);
}

static size_t	ft_str_words(const char *str, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
			words++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (words);
}

static char		**ft_free_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_str_words(s, c);
	if (!(result = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (s[j] == c)
			j++;
		if (!(result[i++] = ft_substr(s, j, ft_str_len(&s[j], c))))
		{
			ft_free_all(result);
			return (NULL);
		}
		j += ft_str_len(&s[j], c);
	}
	result[i] = NULL;
	return (result);
}
