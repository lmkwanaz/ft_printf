/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:54:04 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/14 09:26:58 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t count;
	size_t or;

	or = dstsize;
	count = ft_strlen(dst) + ft_strlen(src);
	while (*dst != '\0' && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	if (dstsize == 0)
		return (ft_strlen(src) + or);
	while (*src != '\0' && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (count);
	return (0);
}
