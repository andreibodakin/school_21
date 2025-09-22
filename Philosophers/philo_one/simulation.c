/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:05:56 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:06:08 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*eat_limit_thread(void *param)
{
	t_phils	*one;
	int		i;

	one = (t_phils *)param;
	i = 0;
	while (i < one->phils_nums)
	{
		if (one->arr[i].eat_count == one->eat_nums)
		{
			pthread_mutex_lock(&one->arr[i++].mutex);
			one->full_phils++;
		}
	}
	if (one->full_phils == one->phils_nums)
	{
		pthread_mutex_lock(&one->write);
		pthread_mutex_unlock(&one->dead);
	}
	return (NULL);
}

void	*check_dead(void *param)
{
	t_phil		*phil;

	phil = (t_phil *)param;
	while (21)
	{
		pthread_mutex_lock(&phil->mutex);
		if (!phil->eating && ft_time() > phil->eat_time_limit)
		{
			ft_talk(phil, DIED);
			pthread_mutex_lock(&phil->phils->write);
			pthread_mutex_unlock(&phil->phils->dead);
			return (NULL);
		}
		pthread_mutex_unlock(&phil->mutex);
		usleep(1000);
	}
	return (NULL);
}

void	*live_thread(void *param)
{
	t_phil		*phil;

	phil = (t_phil *)param;
	phil->eat_time_last = ft_time();
	phil->eat_time_limit = phil->eat_time_last + phil->phils->die_time;
	if (pthread_create(&phil->thread, NULL, &check_dead, (void *)phil))
		return (NULL);
	if (pthread_detach(phil->thread))
		return (NULL);
	while (21)
	{
		ft_take(phil);
		ft_eat(phil);
		ft_sleep(phil);
		ft_talk(phil, THINK);
	}
	return (NULL);
}

int		start_simulation(t_phils *one)
{
	int			i;

	one->base_time = ft_time();
	if (one->eat_nums > 0)
	{
		if (pthread_create(&one->threads, NULL, &eat_limit_thread, (void *)one))
			return (ERROR);
		if (pthread_detach(one->threads))
			return (ERROR);
	}
	i = 0;
	while (i < one->phils_nums)
	{
		if (pthread_create(&one->threads, NULL,
			&live_thread, (void *)(&one->arr[i])))
			return (ERROR);
		if (pthread_detach(one->threads))
			return (ERROR);
		usleep(100);
		i++;
	}
	return (0);
}
