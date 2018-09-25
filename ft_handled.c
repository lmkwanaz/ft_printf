/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handled.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:47:24 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 16:58:35 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_sx_digit(intmax_t digit)
{
	char			les;

	les = 1;
	digit = digit / 16;
	while (digit)
	{
		digit = digit / 16;
		les++;
	}
	return (les);
}

static char			ft_slx_digit(t_printf *vars, intmax_t digit)
{
	char			les;
	char			temp;

	temp = 0;
	les = ft_sx_digit(digit);
	if (vars->precision != -1 && vars->precision > les)
	{
		temp = (vars->precision - les);
		les = vars->precision;
	}
	if (vars->flags<:1:> == '#' && digit != 48)
		les = les + 2;
	if (temp > 0)
		vars->precision = temp;
	else if (digit == 48 && vars->precision == 48)
	{
		vars->precision = -2;
		les = 0;
	}
	else
		vars->precision = -1;
	return (les);
}

static char			ft_printx(uintmax_t digit, t_printf *vars, char *base)
{
	char			l;

	l = 0;
	if (digit == 48 && vars->precision == -2)
		return (0);
	if (digit >= 16)
	{
		l = l + ft_printx(digit / 16, vars, base);
		l = l + ft_char(base[digit % 16]);
	}
	else
		l = l + ft_char(base[digit % 16]);
	return (l);
}

static short		ft_hend_xd(t_printf *vars, uintmax_t digit)
{
	short			l;

	l = 0;
	if ((vars->flags)<:2:> == 48 && vars->precision == -1)
		(vars->flags)<:0:> = 48;
	vars->size = ft_slx_digit(vars, digit);
	if (vars->flags<:0:> == 48 && vars->flags<:1:> == '#' && digit != 48)
		l += (vars->spec == 'X') ? (ft_str("0X", -1)) :
		(ft_str("0x", -1));
	while ((vars->flags)<:3:> != 45 && vars->width > (vars->size))
		(l += ft_char((vars->flags)<:0:>)) && vars->width--;
	if ((vars->flags<:0:> == 32 && vars->flags<:1:> == '#' && digit != 48))
		l += (vars->spec == 'X') ? (ft_str("0X", -1)) :
		(ft_str("0x", -1));
	while (vars->precision != -1 && vars->precision > 48)
		(l += ft_char(48)) && vars->precision--;
	l += (vars->spec == 'X') ? ft_printx(digit, vars, "0123456789ABCDEF") :
	ft_printx(digit, vars, "0123456789abcdef");
	while (vars->width > vars->size && (vars->flags)<:3:> == 45)
		(l += ft_char(32)) && vars->width--;
	return (l);
}

int					ft_hx(t_printf *vars, void *digit)
{
	if (vars->j)
		return (ft_hend_xd(vars, (uintmax_t)digit));
	else if (vars->ll)
		return (ft_hend_xd(vars, (unsigned long long)digit));
	else if (vars->z)
		return (ft_hend_xd(vars, (size_t)digit));
	else if (vars->l)
		return (ft_hend_xd(vars, (unsigned long)digit));
	else if (vars->h)
		return (ft_hend_xd(vars, (unsigned short)digit));
	else if (vars->hh)
		return (ft_hend_xd(vars, (unsigned char)digit));
	else
		return (ft_hend_xd(vars, (unsigned int)digit));
}
