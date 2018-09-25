/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:20:46 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/24 17:04:07 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		p;

	p = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			p += ft_char(*format);
		else
		{
			format++;
			p = p + ft_conversion(&(format), ap);
		}
		format++;
	}
	va_end(ap);
	return (p);
}
