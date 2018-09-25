/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:54:26 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/05/30 16:26:45 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t l;
	size_t length;

	l = 0;
	length = ft_strlen((char *)s) + 1;
	while (l < length)
	{
		if (s[l] == c)
			return ((char *)(s + l));
		l++;
	}
	return (NULL);
}
