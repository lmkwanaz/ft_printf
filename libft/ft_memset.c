/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:40:52 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/05/31 12:27:11 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	d;
	int				m;
	char			*str;

	m = 0;
	d = (unsigned char)c;
	str = (char *)b;
	while (len > 0)
	{
		str[m] = d;
		len--;
		m++;
	}
	return (str);
}
