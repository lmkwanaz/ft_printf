/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 06:46:39 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/20 16:20:19 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

wchar_t		*ft_wchar_dup(wchar_t *src, int len)
{
	int		i;
	wchar_t	*dst;

	i = -1;
	dst = ft_memalloc(sizeof(wchar_t) * len);
	if (dst)
	{
		while (++i < len && src != L'\0')
		{
			if (*(src))
				*(dst++) = *(src++);
			else
				*(dst++) = 0;
		}
	}
	src = dst;
	free(dst);
	return (src);
}

void		ft_prntw_str(t_pist *jar, wchar_t *str)
{
	str = !str ? L"(null)" : str;
	str = jar->h == 0 ? str : ft_wchar_dup(str, jar->max_w);
	jar->min_w -= ft_wstrlen(str);
	if (jar->flag4 == 0)
		ft_spaice(jar);
	ft_wstr(jar, str);
	if (jar->flag4 == '-')
		ft_spaice(jar);
	return ;
}

void		ft_print_wchar(t_pist *jar, wchar_t c)
{
	jar->min_w -= ft_wclen(c);
	if (jar->flag4 == 0)
		ft_spaice(jar);
	ft_putchar(c);
	if (jar->flag4 == '-')
		ft_spaice(jar);
	return ;
}
