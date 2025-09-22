/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:52:02 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/05/02 17:52:02 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	unsigned char	*dst;
	size_t			total;
	size_t			i;

	i = 0;
	total = len * size;
	if (!(dst = malloc(total)))
		return (NULL);
	while (i < total)
		dst[i++] = 0;
	return ((void *)dst);
}
