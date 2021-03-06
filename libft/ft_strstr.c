/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:27:02 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/05/30 17:13:17 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t l;
	size_t m;

	l = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return ((char *)s1);
	while (s1[l] != '\0')
	{
		m = 0;
		while (s2[m] != '\0' && s1[l + m] == s2[m])
			m++;
		if (s2[m] == '\0')
			return ((char *)&s1[l]);
		l++;
	}
	return (NULL);
}
