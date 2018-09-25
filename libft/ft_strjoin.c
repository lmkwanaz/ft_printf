/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:29:15 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 14:15:54 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		m;
	int		jj;
	char	*str;

	l = 0;
	m = 0;
	if (!s1 || !s2)
		return (NULL);
	jj = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (jj + 1));
	if (!str)
		return (NULL);
	while (s1[l] != '\0')
	{
		str[l] = s1[l];
		l++;
	}
	while (s2[m] != '\0')
	{
		str[l + m] = s2[m];
		m++;
	}
	str[l + m] = '\0';
	return (str);
}
