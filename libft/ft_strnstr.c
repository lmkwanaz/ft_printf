/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 15:28:11 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 11:42:59 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	l;
	size_t	m;

	l = 0;
	while (l < n && s1[l] != '\0')
	{
		m = 0;
		while (l + m < n && s1[l + m] == s2[m] && s2[m] != '\0')
			m++;
		if (s2[m] == '\0')
			return ((char *)&s1[l]);
		l++;
	}
	return (0);
}
