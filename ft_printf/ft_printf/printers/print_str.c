/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:00:55 by klavada           #+#    #+#             */
/*   Updated: 2020/07/21 21:00:59 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	print_null_str(t_params *params)
{
	char	*out;

	if (params->flags & FLG_DOT)
		out = "(null)";
	if (params->flags & FLG_MINUS)
		params->count += ft_putnstr(out, ft_strlen(out));
	while (params->width > (int)ft_strlen(out))
	{
		params->count += ft_putchar(' ');
		params->width--;
	}
	if (params->flags & FLG_MINUS)
		params->count += ft_putnstr(out, ft_strlen(out));
}

void			print_str(t_params *params, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char*);
	if (!str)
	{
		print_null_str(params);
		return ;
	}
	if (params->flags & FLG_DOT)
		len = (params->accur < (int)ft_strlen(str)) ? (size_t)params->accur
			: ft_strlen(str);
	else
		len = ft_strlen(str);
	if (params->flags & FLG_MINUS)
		params->count += ft_putnstr(str, len);
	while (params->width > len)
	{
		params->count += ft_putchar(' ');
		params->width--;
	}
	if (!(params->flags & FLG_MINUS))
		params->count += ft_putnstr(str, len);
}
