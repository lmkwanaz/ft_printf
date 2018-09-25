/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:43:27 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 17:13:57 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				ft_size_ptrd(intmax_t digit)
{
	char				les;

	les = 1;
	digit = digit / 16;
	while (digit)
	{
		digit = digit / 16;
		les++;
	}
	return (les);
}

static char				ft_sl_ptr(t_printf *vars, intmax_t digit)
{
	char				les;
	char				temp;

	les = ft_size_ptrd(digit);
	temp = 0;
	if (vars->precision != -1 && vars->precision > les)
	{
		temp = (vars->precision - les);
		les = vars->precision;
	}
	if (digit != 0)
		les = les + 2;
	if (temp > 0)
		vars->precision = temp;
	else if (digit == 0 && vars->precision == 0)
	{
		vars->precision = -2;
		les = 2;
	}
	else
		vars->precision = -1;
	return (les);
}

static char				ft_prnt_ptr(uintmax_t digit, t_printf *vars, char *base)
{
	char				l;

	l = 0;
	if (digit == 0 && vars->precision == -2)
		return (0);
	if (digit >= 16)
	{
		l += ft_prnt_ptr(digit / 16, vars, base);
		l += ft_char(base[digit % 16]);
	}
	else
		l += ft_char(base[digit % 16]);
	return (l);
}

static short			ft_hendp(t_printf *vars, uintmax_t digit)
{
	short				l;

	l = 0;
	if ((vars->flags)<:2:> == 48 && vars->precision == -1)
		(vars->flags)<:0:> = 48;
	vars->size = ft_sl_ptr(vars, digit);
	if (vars->flags<:0:> == 48)
		l += ft_str("0x", -1);
	while ((vars->flags)<:3:> != 45 && vars->width > (vars->size))
		(l += ft_char((vars->flags)<:0:>)) && vars->width--;
	if (vars->flags<:0:> == 32)
		l += ft_str("0x", -1);
	while (vars->precision != -1 && vars->precision > 48)
		(l += ft_char('0')) && vars->precision--;
	l += ft_prnt_ptr(digit, vars, "0123456789abcdef");
	while (vars->width > vars->size && (vars->flags)<:3:> == 45)
		(l += ft_char(32)) && vars->width--;
	return (l);
}

int						ft_hp(t_printf *vars, void *digit)
{
	return (ft_hendp(vars, (uintmax_t)digit));
}
