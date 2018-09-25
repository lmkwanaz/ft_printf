/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:53:10 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 13:59:51 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[l] = (*f)(l, s[l]);
		l++;
	}
	str[l] = '\0';
	return (str);
}
