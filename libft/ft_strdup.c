/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:01:28 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/05/31 14:33:47 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dst;
	int		l;

	l = 0;
	while (s1[l] != '\0')
		l++;
	dst = (char *)malloc(l + 1);
	if (dst == NULL)
		return (NULL);
	l = 0;
	while (s1[l])
	{
		dst[l] = s1[l];
		l++;
	}
	dst[l] = '\0';
	return (dst);
}
