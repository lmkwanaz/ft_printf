/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:51:52 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/16 20:34:36 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if ((unsigned char)src2[l] == (unsigned char)c)
			return ((char *)dst + l + 1);
		l++;
	}
	return (NULL);
}
