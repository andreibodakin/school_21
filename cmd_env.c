/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:55:18 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/23 17:56:20 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	cmd_env(void)
{
	int	i;

	i = -1;
	while (++i < g_env.size)
	{
		if (ft_strchr(g_env.envv[i], '='))
			ft_putendl_fd(g_env.envv[i], 1);
	}
	return (EXIT_SUCCESS);
}
