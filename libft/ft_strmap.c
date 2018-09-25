/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:01:53 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 13:58:31 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		l;
	size_t		len;
	char		*str;

	l = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[l])
	{
		str[l] = (*f)(s[l]);
		l++;
	}
	str[l] = '\0';
	return (str);
}
