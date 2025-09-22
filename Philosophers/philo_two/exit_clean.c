/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:06:39 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 16:09:36 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		exit_msg(char *msg, int status)
{
	write(1, msg, ft_strlen(msg));
	return (status);
}

void	clear_leaks(t_phils *one)
{
	free(one->arr);
}
