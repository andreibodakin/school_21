/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlltoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:19:19 by klavada           #+#    #+#             */
/*   Updated: 2020/07/24 02:21:01 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_get_hex_size(unsigned long long n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char			*ft_hexlltoa(unsigned long long num)
{
	char	*str;
	int		length;

	if (num == 0)
		return (ft_strdup("0"));
	length = ft_get_hex_size(num);
	if (!(str = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	while (num > 0)
	{
		if (num % 16 < 10)
			str[length - 1] = num % 16 + 48;
		else
			str[length - 1] = num % 16 + 87;
		num /= 16;
		length--;
	}
	return (str);
}
