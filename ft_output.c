/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:54:32 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/25 15:50:55 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_output(t_printf *vars, va_list ap)
{
	int l;

	l = 0;
	if (vars->spec == '%')
		l = (ft_percent(vars, '%'));
	else if (vars->spec == 99 || vars->spec == 67)
		l = (ft_hchar(vars, va_arg(ap, void *)));
	else if (vars->spec == 115 || vars->spec == 83)
		l = (ft_hstr(vars, va_arg(ap, char*)));
	else if (vars->spec == 100 || vars->spec == 105 || vars->spec == 68)
		l = (ft_hdigit(vars, va_arg(ap, void *)));
	else if (vars->spec == 117 || vars->spec == 85)
		l = (ft_h_unsd(vars, va_arg(ap, void *)));
	else if (vars->spec == 120 || vars->spec == 88)
		l = (ft_hx(vars, va_arg(ap, void *)));
	else if (vars->spec == 111 || vars->spec == 79)
		l = (ft_ho(vars, va_arg(ap, void *)));
	else if (vars->spec == 112)
		l = (ft_hp(vars, va_arg(ap, void *)));
	else
		l = (ft_hchar(vars, va_arg(ap, void *)));
	ft_strdel(&(vars->flags));
	return (l);
}
