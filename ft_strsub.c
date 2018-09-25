/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:18:29 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 09:50:21 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strsub(char const *str, unsigned int s, size_t l)
{
	char		*ptr;
	size_t		i;

	if (!str)
		return (0);
	ptr = (char*)malloc(sizeof(char) * (l + 1));
	if (ptr)
	{
		i = 0;
		while (i < l)
			ptr[i++] = str[s++];
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}
