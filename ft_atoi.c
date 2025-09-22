/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:48:48 by klavada           #+#    #+#             */
/*   Updated: 2020/05/24 06:56:21 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_over_long_check(long long int result, int sing, char c)
{
	long long int	test;

	test = result * 10 + c - '0';
	if (test < result && sing == -1)
		return (0);
	if (test < result && sing == 1)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	long long int	result;
	int				sing;
	int				over_long_value;

	result = 0;
	sing = 1;
	over_long_value = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sing = -1;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((over_long_value = ft_over_long_check(result, sing, *str)) <= 0)
			return (over_long_value);
		result = result * 10 - '0' + *str++;
	}
	return ((int)result * sing);
}
