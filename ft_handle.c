/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:15:35 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 16:35:02 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_szo_digit(intmax_t digit)
{
	char			les;

	les = 1;
	digit = digit / 8;
	while (digit)
	{
		digit = digit / 8;
		les++;
	}
	return (les);
}

static char			ft_slo_digit(t_printf *vars, intmax_t digit)
{
	char			les;
	char			temp;

	temp = 0;
	les = ft_szo_digit(digit);
	if (vars->precision != -1 && vars->precision > les)
	{
		temp = (vars->precision - les);
		les = vars->precision;
	}
	if (vars->flags<:1:> == '#' && digit != 0)
		les += 1;
	if (temp > 0)
		vars->precision = temp;
	else if (digit == 0 && vars->precision == 0 && vars->flags<:1:> != '#')
	{
		vars->precision = -2;
		les = 0;
	}
	else
		vars->precision = -1;
	return (les);
}

static char			ft_po_digit(uintmax_t digit, t_printf *vars, char *base)
{
	char			l;

	l = 0;
	if (digit == 0 && vars->precision == -2)
		return (0);
	if (digit >= 8)
	{
		l += ft_po_digit(digit / 8, vars, base);
		l += ft_char(base[digit % 8]);
	}
	else
		l = l + ft_char(base[digit % 8]);
	return (l);
}

static short		ft_hend_od(t_printf *vars, uintmax_t digit)
{
	short			l;

	l = 0;
	if ((vars->flags)<:2:> == '0' && vars->precision == -1)
		(vars->flags)<:0:> = '0';
	vars->size = ft_slo_digit(vars, digit);
	if (vars->flags<:0:> == '0' && vars->flags<:1:> == '#' && digit != 0)
		l += ft_char('0');
	while ((vars->flags)<:3:> != '-' && vars->width > (vars->size))
		(l += ft_char((vars->flags)<:0:>)) && vars->width--;
	if (vars->flags<:0:> == ' ' && vars->flags<:1:> == '#' && digit != 0)
		l += ft_char('0');
	while (vars->precision != -1 && vars->precision > 0)
		(l += ft_char('0')) && vars->precision--;
	l += ft_po_digit(digit, vars, "01234567");
	while (vars->width > vars->size && (vars->flags)<:3:> == '-')
		(l += ft_char(' ')) && vars->width--;
	return (l);
}

int					ft_ho(t_printf *vars, void *digit)
{
	if (vars->spec == 'O')
		return (ft_hend_od(vars, (unsigned long)digit));
	else if (vars->j)
		return (ft_hend_od(vars, (uintmax_t)digit));
	else if (vars->ll)
		return (ft_hend_od(vars, (unsigned long long)digit));
	else if (vars->z)
		return (ft_hend_od(vars, (size_t)digit));
	else if (vars->l)
		return (ft_hend_od(vars, (unsigned long)digit));
	else if (vars->h)
		return (ft_hend_od(vars, (unsigned short)digit));
	else if (vars->hh)
		return (ft_hend_od(vars, (unsigned char)digit));
	else
		return (ft_hend_od(vars, (unsigned int)digit));
}
