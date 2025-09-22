/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:59:19 by klavada           #+#    #+#             */
/*   Updated: 2020/07/21 20:59:25 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static	void	hex_helper_print(char *str, t_params *params)
{
	int		accur;

	if (params->flags & FLG_DOT)
	{
		accur = params->accur;
		while (accur > (int)ft_strlen(str))
		{
			params->count += ft_putchar('0');
			accur--;
		}
	}
	params->count += ft_putnstr(str, ft_strlen(str));
}

static	void	hex_helper(char *str, t_params *params)
{
	if (params->flags & FLG_MINUS)
		hex_helper_print(str, params);
	if ((size_t)params->accur < ft_strlen(str))
		params->accur = ft_strlen(str);
	while (params->width > params->accur)
	{
		params->count += ft_putchar(((params->flags & FLG_MINUS) &&
										(params->flags & FLG_DOT)) ? '0' : ' ');
		params->width--;
	}
	if (params->flags & ~FLG_MINUS)
		hex_helper_print(str, params);
}

void			print_hex(t_params *params, va_list args)
{
	if (params && args)
		return ;
	return ;
	char			*num_str;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (!num && (params->flags & FLG_DOT) && !params->accur)
	{
		while (params->width--)
			params->count += ft_putchar(' ');
		return ;
	}
	num_str = ft_hextoa(num, params->type);
	hex_helper(num_str, params);
	free(num_str);
}
