/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <klavada@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:00:37 by klavada           #+#    #+#             */
/*   Updated: 2020/07/21 21:00:42 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

// static	void	ptr_helper_print(char *str, t_params *params,
// 									unsigned long long ptr)
// {
// 	int		accur;

// 	if (ptr != 0)
// 	{
// 		params->count += ft_putnstr("0x", 2);
// 		if (params->point == true)
// 		{
// 			accur = params->accur;
// 			while (accur > (int)ft_strlen(str))
// 			{
// 				params->count += ft_putchar('0');
// 				accur--;
// 			}
// 		}
// 	}
// 	params->count += ft_putnstr(str, ft_strlen(str));
// }

// static	void	ptr_helper(char *str, t_params *params, unsigned long long ptr)
// {
// 	int prefix;

// 	prefix = (ptr != 0) ? 2 : 0;
// 	if (params->m_flag == true)
// 		ptr_helper_print(str, params, ptr);
// 	if ((size_t)params->accur < ft_strlen(str) || ptr == 0)
// 		params->accur = ft_strlen(str);
// 	while (params->width - prefix > params->accur)
// 	{
// 		params->count += ft_putchar(' ');
// 		params->width--;
// 	}
// 	if (params->m_flag == false)
// 		ptr_helper_print(str, params, ptr);
// }

void			print_ptr(t_params *params, va_list args)
{
	if (params && args)
		return ;
	return ;
// 	char				*ptr_str;
// 	unsigned long long	ptr;

// 	ptr = va_arg(args, unsigned long long);
// 	if (ptr == 0)
// 		ptr_str = ft_strdup("(nil)");
// 	else
// 		ptr_str = ft_hexlltoa(ptr);
// 	ptr_helper(ptr_str, params, ptr);
// 	free(ptr_str);
}
