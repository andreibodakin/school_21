/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:54:10 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/02 15:54:10 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(long long int numb, int sign, char c)
{
	long long int	res;

	res = numb * 10 + c - '0';
	if (res < numb && sign == -1)
		return (0);
	if (res < numb && sign == 1)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	long long int	numb;
	int				sign;
	int				check;

	numb = 0;
	sign = 1;
	check = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
					*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((check = ft_check(numb, sign, *str)) <= 0)
			return (check);
		numb = numb * 10 - '0' + *str++;
	}
	return ((int)numb * sign);
}
