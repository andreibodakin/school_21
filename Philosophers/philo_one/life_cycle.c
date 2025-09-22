/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:04:51 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:04:59 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_take(t_phil *phil)
{
	pthread_mutex_lock(&phil->phils->forks[phil->left_fork]);
	ft_talk(phil, TAKE);
	pthread_mutex_lock(&phil->phils->forks[phil->right_fork]);
	ft_talk(phil, TAKE);
}

void	ft_eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->mutex);
	phil->eating = 1;
	phil->eat_time_last = ft_time();
	phil->eat_time_limit = phil->eat_time_last + phil->phils->die_time;
	ft_talk(phil, EAT);
	usleep(phil->phils->eat_time * 1000);
	phil->eat_count++;
	phil->eating = 0;
	pthread_mutex_unlock(&phil->mutex);
}

void	ft_sleep(t_phil *phil)
{
	ft_talk(phil, SLEEP);
	pthread_mutex_unlock(&phil->phils->forks[phil->left_fork]);
	pthread_mutex_unlock(&phil->phils->forks[phil->right_fork]);
	usleep(phil->phils->sleep_time * 1000);
}
