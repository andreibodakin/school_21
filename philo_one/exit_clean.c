/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:04:34 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:04:42 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		exit_msg(char *msg, int status)
{
	write(1, msg, ft_strlen(msg));
	return (status);
}

void	clear_leaks(t_phils *one)
{
	int i;

	i = 0;
	while (i < one->phils_nums)
	{
		pthread_mutex_destroy(&one->forks[i]);
		pthread_mutex_destroy(&one->arr[i].mutex);
		i++;
	}
	free(one->forks);
	free(one->arr);
	pthread_mutex_destroy(&one->write);
	pthread_mutex_destroy(&one->dead);
}
