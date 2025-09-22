/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 23:38:59 by klavada           #+#    #+#             */
/*   Updated: 2020/05/24 06:47:57 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int_min(void)
{
	char	*result;

	result = (char *)malloc(12 * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}

static	int	ft_chars_num(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

static char	*ft_malloc_str(int chars, int sing)
{
	char	*result;

	if (sing < 0)
	{
		result = (char *)malloc((chars + 2) * sizeof(char));
		if (result == NULL)
			return (NULL);
	}
	else
	{
		result = (char *)malloc((chars + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		sing;
	int		chars;
	int		i;

	if (n == -2147483648)
		return (ft_int_min());
	if ((sing = n) < 0)
		n = -n;
	chars = ft_chars_num(n);
	result = ft_malloc_str(chars, sing);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (n == 0)
		result[i++] = '0';
	while (n)
	{
		result[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sing < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_reverse(result));
}
