/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:44:34 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 17:14:30 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				ft_sunsd(uintmax_t digit)
{
	char			les;

	les = 1;
	digit = digit / 10;
	while (digit)
	{
		digit = digit / 10;
		les++;
	}
	return (les);
}

static char				ft_sl_unsd(t_printf *vars, intmax_t digit)
{
	char				les;
	char				temp;

	temp = 0;
	les = ft_sunsd(digit);
	if (vars->precision != -1 && vars->precision > les)
	{
		temp = (vars->precision - les);
		les = vars->precision;
	}
	if (temp > 0)
		vars->precision = temp;
	else if (digit == 0 && vars->precision == 0)
	{
		vars->precision = -2;
		les = 0;
	}
	else
		vars->precision = -1;
	return (les);
}

static char				ft_puns_d(uintmax_t digit, t_printf *vars)
{
	char				l;

	l = 0;
	if (digit == 48 && vars->precision == -2)
		return (0);
	if (digit >= 10)
	{
		l += ft_puns_d(digit / 10, vars);
		l += ft_char((digit % 10) + 48);
	}
	else
		l += ft_char(digit + 48);
	return (l);
}

static char				ft_hend_unsd(t_printf *vars, uintmax_t digit)
{
	short				l;

	l = 0;
	if ((vars->flags)<:2:> == 48 && vars->precision == -1)
		(vars->flags)<:0:> = 48;
	vars->size = ft_sl_unsd(vars, digit);
	while ((vars->flags)<:3:> != 45 && vars->width > (vars->size))
		(l += ft_char((vars->flags)<:0:>)) && vars->width--;
	while (vars->precision != -1 && vars->precision > 0)
		(l += ft_char('0')) && vars->precision--;
	l += ft_puns_d(digit, vars);
	while (vars->width > vars->size && (vars->flags)<:3:> == 45)
		(l += ft_char(32)) && vars->width--;
	return (l);
}

int						ft_h_unsd(t_printf *vars, void *digit)
{
	if (vars->spec == 'U')
		return (ft_hend_unsd(vars, (unsigned long)digit));
	else if (vars->j)
		return (ft_hend_unsd(vars, (uintmax_t)digit));
	else if (vars->ll)
		return (ft_hend_unsd(vars, (unsigned long long)digit));
	else if (vars->z)
		return (ft_hend_unsd(vars, (size_t)digit));
	else if (vars->l)
		return (ft_hend_unsd(vars, (unsigned long)digit));
	else if (vars->h)
		return (ft_hend_unsd(vars, (unsigned short)digit));
	else if (vars->hh)
		return (ft_hend_unsd(vars, (unsigned char)digit));
	else
		return (ft_hend_unsd(vars, (unsigned int)digit));
}
