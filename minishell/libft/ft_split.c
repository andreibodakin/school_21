/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:31:43 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/03 18:31:43 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_leng(const char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i++])
		len++;
	return (len);
}

static size_t	ft_str_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (count);
}

static char		**ft_error_mal(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char			**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	count;
	char	**arr;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	count = ft_str_count(s, c);
	if (!(arr = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		while (s[k] == c)
			k++;
		if (!(arr[i++] = ft_substr(s, k, ft_str_leng(&s[k], c))))
		{
			ft_error_mal(arr);
			return (NULL);
		}
		k += ft_str_leng(&s[k], c);
	}
	arr[i] = NULL;
	return (arr);
}
