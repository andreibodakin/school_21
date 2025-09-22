/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:09:39 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:09:44 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

unsigned long	ft_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long)1000) + (tv.tv_usec / 1000));
}

char			*get_status(int status)
{
	if (status == TAKE)
		return (" has taken a fork\n");
	else if (status == EAT)
		return (" is eating\n");
	else if (status == SLEEP)
		return (" is sleeping\n");
	else if (status == THINK)
		return (" is thinking\n");
	else if (status == DIED)
		return (" died\n");
	return (NULL);
}

void			print_time(unsigned long base_time)
{
	char *time;

	time = ft_itoa(ft_time() - base_time);
	write(1, time, ft_strlen(time));
	write(1, "ms ", 3);
	free(time);
}

void			print_status(int status)
{
	char *str;

	str = get_status(status);
	write(1, str, ft_strlen(str));
}

void			ft_talk(t_phil *phil, int status)
{
	char		*nbr;

	sem_wait(phil->phils->write);
	print_time(phil->phils->base_time);
	nbr = ft_itoa(phil->id + 1);
	write(1, nbr, ft_strlen(nbr));
	free(nbr);
	print_status(status);
	sem_post(phil->phils->write);
}
