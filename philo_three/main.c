/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:11:20 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:11:26 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		init_phils(t_phils *one)
{
	int		i;
	char	*id;

	i = 0;
	while (i < one->phils_nums)
	{
		one->arr[i].id = i;
		one->arr[i].eating = 0;
		one->arr[i].eat_count = 0;
		one->arr[i].eat_max = one->eat_nums;
		one->arr[i].stop = 0;
		one->arr[i].phils = one;
		id = ft_itoa(i + 1);
		if ((one->arr[i].semp = sem_open(id, O_CREAT, 0644, 1)) == SEM_FAILED)
			return (ERROR);
		sem_unlink(id);
		free(id);
		id = ft_itoa(one->phils_nums + i + 1);
		if ((one->arr[i].full = sem_open(id, O_CREAT, 0644, 0)) == SEM_FAILED)
			return (ERROR);
		sem_unlink(id);
		free(id);
		i++;
	}
	return (SUCCESS);
}

int		init_semaphore(t_phils *one)
{
	if ((one->write = sem_open("write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (ERROR);
	sem_unlink("write");
	if ((one->dead = sem_open("dead", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (ERROR);
	sem_unlink("dead");
	if ((one->forks = sem_open("forks", O_CREAT, 0644, one->phils_nums))
			== SEM_FAILED)
		return (ERROR);
	sem_unlink("forks");
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
	one->stop = 0;
	if (ac == 6)
		one->eat_nums = ft_atoi(av[5]);
	if (one->phils_nums < 2 || one->phils_nums > 200 || one->die_time < 60
		|| one->eat_time < 60 || one->sleep_time < 60 || one->eat_nums < 0)
		return (ERROR);
	one->arr = NULL;
	if (!(one->arr = (t_phil *)malloc(sizeof(t_phil) * one->phils_nums)))
		return (ERROR);
	if ((init_phils(one)) != SUCCESS)
		return (ERROR);
	if ((init_semaphore(one)) != SUCCESS)
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
	sem_wait(one.dead);
	clear_leaks(&one);
	return (SUCCESS);
}
