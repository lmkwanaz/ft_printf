/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:45:09 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/16 20:33:56 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	l;
	char	*dst2;
	char	*src2;

	l = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (l < n)
	{
		dst2[l] = src2[l];
		l++;
	}
	return (dst);
}
