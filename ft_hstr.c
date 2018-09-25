/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:02:12 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/26 15:29:30 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hstr(t_printf *vars, char *str)
{
	int l;

	vars->size = (str != NULL) ? ft_strlen((char *)str) : 6;
	l = 0;
	vars->size = !vars->precision ? vars->width : vars->size;
	if ((vars->flags)<:2:> == 48)
		(vars->flags)<:0:> = 48;
	while ((vars->flags)<:3:> != 45 && vars->width > vars->size)
		(l += ft_char((vars->flags)<:0:>)) && (vars->width)--;
	while ((vars->flags)<:3:> != 45 && vars->width > vars->precision &&
			vars->precision != -1 && (vars->size > vars->precision))
		l += ft_char((vars->flags)<:0:>) && vars->width--;
	if (vars->spec == 's' && !vars->l)
		l += ft_str((char *)str, vars->precision);
	else if (vars->spec == 'S' || (vars->spec == 's' && vars->l))
		l += ft_wstr((wchar_t *)str, vars->precision);
	while ((vars->flags)<:3:> == 45 && vars->width > vars->size)
		l += ft_char(32) && vars->width--;
	while ((vars->flags)<:3:> == 45 && vars->width > vars->precision &&
			vars->precision != -1 && (vars->size-- - vars->precision))
		l += ft_char(32);
	return (l);
}
