/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:47:39 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/17 00:37:13 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			l;
	unsigned char	*str1;
	unsigned char	*str2;

	l = 0;
	if (n == 0)
	{
		return (0);
	}
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[l] == str2[l] && l < n - 1)
		l++;
	if (n == l)
		return (0);
	return (str1[l] - str2[l]);
}
