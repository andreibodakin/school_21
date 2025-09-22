/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:05:06 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:05:11 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_phils(t_phils *one)
{
	int i;

	i = 0;
	while (i < one->phils_nums)
	{
		one->arr[i].id = i;
		one->arr[i].eat_count = 0;
		one->arr[i].phils = one;
		one->arr[i].left_fork = i;
		one->arr[i].right_fork = (i + 1) % one->phils_nums;
		if (pthread_mutex_init(&one->arr[i].mutex, NULL))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int		init_mutex(t_phils *one)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&one->write, NULL))
		return (ERROR);
	if (pthread_mutex_init(&one->dead, NULL))
		return (ERROR);
	pthread_mutex_lock(&one->dead);
	if (!(one->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
	* one->phils_nums)))
		return (ERROR);
	while (i < one->phils_nums)
		if (pthread_mutex_init(&one->forks[i++], NULL))
			return (ERROR);
	return (SUCCESS);
}

int		init_struct(int ac, char **av, t_phils *one)
{
	one->phils_nums = ft_atoi(av[1]);
	one->die_time = ft_atoi(av[2]);
	one->eat_time = ft_atoi(av[3]);
	one->sleep_time = ft_atoi(av[4]);
	one->eat_nums = 0;
	one->full_phils = 0;
	if (ac == 6)
		one->eat_nums = ft_atoi(av[5]);
	if (one->phils_nums < 2 || one->phils_nums > 200 || one->die_time < 60
		|| one->eat_time < 60 || one->sleep_time < 60 || one->eat_nums < 0)
		return (ERROR);
	one->forks = NULL;
	one->arr = NULL;
	if (!(one->arr = (t_phil *)malloc(sizeof(t_phil) * one->phils_nums)))
		return (ERROR);
	if ((init_phils(one)) != SUCCESS)
		return (ERROR);
	if ((init_mutex(one)) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	t_phils	one;

	if (ac < 5 || ac > 6)
		return (exit_msg("Wrong arguments number!\n", ERROR));
	if ((init_struct(ac, av, &one)) != SUCCESS)
		return (exit_msg("Wrong arguments value!\n", ERROR));
	if ((start_simulation(&one)) != SUCCESS)
		return (exit_msg("Wrong simulation start!\n", ERROR));
	pthread_mutex_lock(&one.dead);
	clear_leaks(&one);
	return (SUCCESS);
}
