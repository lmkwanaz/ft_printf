/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:18:18 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 11:24:24 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int l;

	l = ft_strlen(s);
	if (c == 0)
		return ((char *)s + l);
	while (l >= 0)
	{
		if (s[l] == c)
			return ((char *)s + l);
		l--;
	}
	return (NULL);
}
