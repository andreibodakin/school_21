/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:10:43 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:10:50 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	exit_fatal(void)
{
	write(2, "error: fatal\n", 13);
	exit(EXIT_FAILURE);
}

int		exit_msg(char *msg, int status)
{
	write(1, msg, ft_strlen(msg));
	return (status);
}

void	clear_leaks(t_phils *one)
{
	int	i;

	i = 0;
	while (i < one->phils_nums)
	{
		kill(one->arr[i].pid, SIGKILL);
		i++;
	}
	free(one->arr);
}
