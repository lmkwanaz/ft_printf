/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:15:21 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/15 09:27:23 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	size_t			l;
	unsigned char	*str;

	str = (unsigned char *)s;
	d = (unsigned char)c;
	l = 0;
	while (l < n)
	{
		if (str[l] == (unsigned char)c)
			return (str + l);
		l++;
	}
	return (NULL);
}
