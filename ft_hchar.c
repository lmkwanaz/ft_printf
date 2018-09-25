/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:24:07 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/26 15:32:16 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hchar(t_printf *vars, void *c)
{
	int l;

	l = 0;
	if ((vars->flags)<:2:> == 48)
		(vars->flags)<:0:> = 48;
	if ((vars->flags)<:3:> != 45 && vars->width > 1)
		while (((vars->width)-- - 1))
			l = l + ft_char((vars->flags)<:0:>);
	if (vars->spec == 99 && !vars->l)
		l = l + ft_char((int)c);
	else if (vars->spec == 67 || (vars->spec == 99 && vars->l))
		l = l + ft_char((int)c);
	else
		l = l + ft_char(vars->spec);
	if (vars->width > 1 && (vars->flags)<:3:> == 45)
		while ((vars->width)-- - 1)
			l = l + ft_char(' ');
	return (l);
}
