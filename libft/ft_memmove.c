/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:59:40 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/16 21:19:17 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *l;
	char *m;

	l = (char*)dst;
	m = (char*)src;
	if (m < l)
		while (len--)
		{
			l[len] = m[len];
		}
	else
		ft_memcpy(l, m, len);
	return (dst);
}
