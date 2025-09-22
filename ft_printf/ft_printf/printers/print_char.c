/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:58:47 by klavada           #+#    #+#             */
/*   Updated: 2020/07/21 20:58:52 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_char(t_params *params, va_list args)
{
	unsigned char	symbol;

	if (params->type == '%')
		symbol = '%';
	else
		symbol = (unsigned char)va_arg(args, int);
	if (params->flags & FLG_MINUS)
		params->count += ft_putchar(symbol);
	while (params->width > 1)
	{
		params->count += ft_putchar(' ');
		params->width--;
	}
	if (!(params->flags & FLG_MINUS))
		params->count += ft_putchar(symbol);
}
