/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:11:09 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:11:13 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_take(t_phil *phil)
{
	sem_wait(phil->phils->forks);
	ft_talk(phil, TAKE);
	sem_wait(phil->phils->forks);
	ft_talk(phil, TAKE);
}

void	ft_eat(t_phil *phil)
{
	sem_wait(phil->semp);
	phil->eating = 1;
	phil->eat_time_last = ft_time();
	phil->eat_time_limit = phil->eat_time_last + phil->phils->die_time;
	ft_talk(phil, EAT);
	usleep(phil->phils->eat_time * 1000);
	phil->eat_count++;
	phil->eating = 0;
	sem_post(phil->full);
	if (phil->eat_count == phil->eat_max)
		phil->stop = 1;
	sem_post(phil->semp);
}

void	ft_sleep(t_phil *phil)
{
	ft_talk(phil, SLEEP);
	sem_post(phil->phils->forks);
	sem_post(phil->phils->forks);
	usleep(phil->phils->sleep_time * 1000);
}
