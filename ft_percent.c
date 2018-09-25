/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:18:38 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/25 10:59:03 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(t_printf *vars, char c)
{
	int l;

	l = 0;
	if ((vars->flags)<:2:> == 48)
		(vars->flags)<:0:> = 48;
	if ((vars->flags)<:3:> != 45 && vars->width > 1)
		while (((vars->width)-- - 1))
			l = l + ft_char((vars->flags)<:0:>);
	l = l + ft_char(c);
	if (vars->width > 1 && (vars->flags)<:3:> == 45)
		while ((vars->width)-- - 1)
			l = l + ft_char(' ');
	return (l);
}
