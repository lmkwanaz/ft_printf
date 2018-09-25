/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:04:05 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 14:08:28 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*str;

	l = 0;
	if (!s)
		return (NULL);
	str = (char*)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (l < len)
	{
		str[l] = s[start + l];
		l++;
	}
	str[l] = '\0';
	return (str);
}
