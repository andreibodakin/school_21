/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:25:36 by klavada           #+#    #+#             */
/*   Updated: 2020/07/24 12:51:07 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "headers/ft_printf.h"

# define ARG "|test %s|", "passed"

int	main(void)
{
	ft_printf(ARG);
	ft_printf("\n");
	printf(ARG);
	printf("\n");
	return (0);
}
