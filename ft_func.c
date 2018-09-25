/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:29:50 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/26 15:21:45 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	size_wchar(unsigned int len)
{
	if (len <= 127)
		return (1);
	else if (len >= 128 && len <= 2047)
		return (2);
	else if (len >= 2048 && len <= 65535)
		return (3);
	else if (len >= 65536 && len <= 2097151)
		return (4);
	else
		return (0);
}

char			ft_wchar(wchar_t len)
{
	char		l;
	char		m;
	unsigned	byt;

	l = 0;
	m = size_wchar(len);
	if (m == 1)
		return (ft_char(len));
	byt = (240 << (4 - m)) | (len >> ((m - 1) * 6));
	l += ft_char(byt);
	m--;
	while (m--)
	{
		byt = ((len >> ((m) * 6)) & 63) | 128;
		l += ft_char(byt);
	}
	return (l);
}

int				ft_wstr(wchar_t *w, int precision)
{
	int l;

	l = 0;
	if (w == NULL)
		return (ft_str("(null)", precision));
	while (*w != '\0')
	{
		l = l + ft_wchar(*w);
		w++;
	}
	return (l);
}
