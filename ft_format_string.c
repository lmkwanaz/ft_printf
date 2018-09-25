/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:08:26 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/26 16:02:59 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	len_len(t_printf *vars)
{
	vars->flags = ft_strdup(" *****");
	vars->width = -1;
	vars->precision = -1;
	vars->hh = 48;
	vars->h = 48;
	vars->l = 48;
	vars->ll = 48;
	vars->j = 48;
	vars->z = 48;
}

static	void	ft_flags(char **format, t_printf *vars)
{
	char c;

	c = **format;
	if (c == 45)
		(vars->flags)[0] = 45;
	else if (c == 43)
		(vars->flags)[1] = 43;
	else if (c == 32)
		(vars->flags)[2] = 32;
	else if (c == 35)
		(vars->flags)[3] = 35;
	else if (c == 48)
		(vars->flags)[4] = 48;
}

static	char	ft_double(char *format, char c)
{
	char l;

	l = 0;
	while (ft_strchr_a("+-#0 .123456789hljz", *format))
	{
		if (*format == c)
			l++;
		format++;
	}
	if (l % 2 != 0)
		return (1);
	else
		return (0);
}

static	void	ft_modie(char **format, t_printf *vars)
{
	char p;

	p = **format;
	if (p == 'h' && !(vars->h) && !(vars->hh))
	{
		if (ft_double(&p, 'h'))
			vars->h = 1;
		else
			vars->hh = 1;
	}
	if (p == 'l' && !(vars->l) && !(vars->ll))
	{
		if (ft_double(&p, 'l'))
			vars->l = 1;
		else
			vars->ll = 1;
	}
	if (p == 'j')
		vars->j = 1;
	if (p == 'z')
		vars->z = 1;
}

int				ft_conversion(char **format, va_list va)
{
	t_printf		vars;

	len_len(&vars);
	while ((ft_strchr_a("+-#0 .123456789hljz", **format)))
	{
		(ft_strchr_a("#0-+ ", **format)) ? ft_flags(format, &vars) : 48;
		if (ft_strchr_a("123456789", **format))
		{
			vars.width = ft_atoi_a(format);
			continue ;
		}
		if (**format == 46 && (*format)++)
		{
			vars.precision = ft_atoi_a(format);
			continue ;
		}
		(ft_strchr_a("hlzj", **format)) ? ft_modie(format, &vars) : 48;
		(*format)++;
	}
	if (ft_strchr_a("%sSpdDioOuUxXcC", **format))
		vars.spec = **format;
	else
		vars.spec = **format;
	return (ft_output(&vars, va));
}
