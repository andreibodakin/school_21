/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:45:00 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/05 14:45:06 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int		cmd_pwd(void)
{
	char	buff[1024];

	if (!getcwd(buff, 1024))
		return (errno);
	ft_putendl_fd(buff, 1);
	return (EXIT_SUCCESS);
}
