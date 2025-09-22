/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:12:06 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:12:12 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*eat_limit_thread(void *param)
{
	t_phils	*one;
	int		i;
	int		num;

	one = (t_phils *)param;
	num = 0;
	while (num < one->eat_nums)
	{
		i = 0;
		while (i < one->phils_nums)
		{
			sem_wait(one->arr[i].full);
			i++;
		}
		num++;
	}
	one->stop = 1;
	sem_post(one->dead);
	return (NULL);
}

void	*check_dead(void *param)
{
	t_phil		*phil;

	phil = (t_phil *)param;
	while (21)
	{
		sem_wait(phil->semp);
		if (!phil->eating && ft_time() > phil->eat_time_limit)
		{
			ft_talk(phil, DIED);
			sem_wait(phil->phils->write);
			sem_post(phil->phils->dead);
			return (NULL);
		}
		sem_post(phil->semp);
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
	usleep(100);
	while (21)
	{
		ft_take(phil);
		ft_eat(phil);
		ft_sleep(phil);
		ft_talk(phil, THINK);
	}
	return (NULL);
}

void	start_process(t_phils *one)
{
	int		i;

	i = 0;
	while (i < one->phils_nums)
	{
		one->arr[i].pid = fork();
		if (one->arr[i].pid < 0)
			exit_fatal();
		if (one->arr[i].pid == 0)
		{
			live_thread((void *)(&one->arr[i]));
			exit(EXIT_SUCCESS);
		}
		else
		{
			usleep(100);
			i++;
		}
	}
}

int		start_simulation(t_phils *one)
{
	one->base_time = ft_time();
	if (one->eat_nums > 0)
	{
		if (pthread_create(&one->threads, NULL, &eat_limit_thread, (void *)one))
			return (ERROR);
		if (pthread_detach(one->threads))
			return (ERROR);
		usleep(100);
	}
	start_process(one);
	return (0);
}
