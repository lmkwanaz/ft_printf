/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:46:02 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 16:04:53 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				ft_sized(intmax_t digit)
{
	char				les;

	les = 1;
	digit /= 10;
	while (digit)
	{
		digit = digit / 10;
		les++;
	}
	return (les);
}

static char				ft_lend(t_printf *vars, intmax_t digit)
{
	char				les;
	char				temp;

	temp = 0;
	les = ft_sized(digit);
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
	if ((digit < 0) || (((vars->flags)[4] == 43 || (vars->flags)[5] == 32) &&
	digit >= 0))
		les++;
	return (les);
}

static char				ft_printd(intmax_t digit, t_printf *vars)
{
	char len;

	len = 0;
	if (digit == 48 && vars->precision == -2)
		return (0);
	if (-10 < digit && digit < 10)
		len += ft_char(ABS(digit) + '0');
	else
	{
		len += ft_printd(digit / 10, vars);
		len += ft_printd(digit % 10, vars);
	}
	return (len);
}

static short			ft_hendd(t_printf *vars, intmax_t digit, int *len)
{
	if ((vars->flags)<:2:> == '0' && vars->precision == -1)
		(vars->flags)<:0:> = '0';
	vars->size = ft_lend(vars, digit);
	if (digit < 0 && vars->flags<:0:> == '0')
		*len += ft_char('-');
	else if (digit >= 0 && vars->flags<:0:> == '0' && vars->flags<:4:> == '+')
		*len += ft_char('+');
	else if (vars->flags<:0:> == '0' && vars->flags<:5:> == ' ')
		*len += ft_char(' ');
	while ((vars->flags)<:3:> != '-' && vars->width > (vars->size))
		(*len += ft_char((vars->flags)<:0:>)) && vars->width--;
	if ((vars->flags)<:4:> == '+' && digit >= 0 && vars->flags<:0:> != '0')
		*len += ft_char('+');
	else if (digit < 0 && vars->flags<:0:> == ' ' && vars->flags<:0:> != '0')
		*len += ft_char('-');
	else if ((vars->flags)<:5:> == ' ' && digit >= 0 && vars->flags<:0:> != '0')
		*len += ft_char(' ');
	while (vars->precision != -1 && vars->precision > 0)
		(*len += ft_char('0')) && vars->precision--;
	*len += ft_printd(digit, vars);
	while (vars->width > vars->size && (vars->flags)<:3:> == '-')
		(*len += ft_char(' ')) && vars->width--;
	return (*len);
}

int						ft_hdigit(t_printf *vars, void *digit)
{
	int l;

	l = 0;
	if (vars->spec == 'D')
		(ft_hendd(vars, (long)digit, &l));
	else if (vars->j)
		(ft_hendd(vars, (intmax_t)digit, &l));
	else if (vars->ll)
		(ft_hendd(vars, (long long)digit, &l));
	else if (vars->z)
		(ft_hendd(vars, (size_t)digit, &l));
	else if (vars->l)
		(ft_hendd(vars, (long)digit, &l));
	else if (vars->h)
		(ft_hendd(vars, (short)digit, &l));
	else if (vars->hh)
		(ft_hendd(vars, (char)digit, &l));
	else
		(ft_hendd(vars, (int)digit, &l));
	return (l);
}
