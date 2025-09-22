/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:06:14 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:06:20 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int i;
	int	num;
	int	sing;

	i = 0;
	num = 0;
	sing = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sing = ((str[i++] == '-') ? -1 : 1);
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	return (num * sing);
}

char	*ft_strdup(char *str)
{
	int		size;
	char	*new;

	size = ft_strlen(str);
	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

int		get_size(unsigned long n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(unsigned long n)
{
	char	*result;
	int		size;
	int		i;

	size = get_size(n);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i <= size)
	{
		result[size - i] = (n % 10) + '0';
		n = n / 10;
	}
	result[size] = '\0';
	return (result);
}
