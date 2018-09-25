/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:15:46 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 14:39:14 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					*ft_memcpy(void *dst, const void *src, size_t l)
{
	size_t				m;
	unsigned char		*dst1;
	const unsigned char *src1;

	dst1 = dst;
	src1 = src;
	m = 0;
	while (m < l)
	{
		dst1[m] = src1[m];
		m++;
	}
	return (dst);
}
