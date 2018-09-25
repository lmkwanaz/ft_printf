/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:48:15 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/05/30 17:08:19 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int l;
	int n;

	l = 0;
	n = (int)len;
	while (l < n && src[l] != '\0')
	{
		dst[l] = src[l];
		l++;
	}
	while (l < n)
	{
		dst[l] = '\0';
		l++;
	}
	return (dst);
}
