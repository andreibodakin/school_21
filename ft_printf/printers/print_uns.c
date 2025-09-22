/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:01:18 by klavada           #+#    #+#             */
/*   Updated: 2020/07/21 21:01:24 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

// static	void	uns_helper_print(char *str, t_params *params)
// {
// 	int		accur;

// 	if (params->point == true)
// 	{
// 		accur = params->accur;
// 		while (accur > (int)ft_strlen(str))
// 		{
// 			params->count += ft_putchar('0');
// 			accur--;
// 		}
// 	}
// 	params->count += ft_putnstr(str, ft_strlen(str));
// }

// static	void	uns_helper(char *str, t_params *params)
// {
// 	if (params->m_flag == true)
// 		uns_helper_print(str, params);
// 	if ((size_t)params->accur < ft_strlen(str))
// 		params->accur = ft_strlen(str);
// 	while (params->width > params->accur)
// 	{
// 		params->count += ft_putchar((params->z_flag == true &&
// 										params->point == false) ? '0' : ' ');
// 		params->width--;
// 	}
// 	if (params->m_flag == false)
// 		uns_helper_print(str, params);
// }

void			print_uns(t_params *params, va_list args)
{
	if (params && args)
		return ;
	return ;
// 	char			*num_str;
// 	unsigned int	num;

// 	num = va_arg(args, unsigned int);
// 	if (!num && params->point == true && !params->accur)
// 	{
// 		while (params->width--)
// 			params->count += ft_putchar(' ');
// 		return ;
// 	}
// 	num_str = ft_uitoa(num);
// 	uns_helper(num_str, params);
// 	free(num_str);
}
