/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:11:54 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/25 14:20:06 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define NOSTRING "(null)"

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct	s_printf
{
	char		*flags;
	short		width;
	short		precision;
	char		hh;
	char		h;
	char		l;
	char		ll;
	char		j;
	char		z;
	char		spec;
	short		size;
}				t_printf;

int				ft_handle(char *format, va_list ap, t_printf *vars);
int				ft_printf(char *format, ...);
int				ft_hchar(t_printf *vars, void *c);
int				ft_hstr(t_printf *vars, char *s);
int				ft_hdigit(t_printf *vars, void *digit);
int				ft_char(int c);
int				ft_hptr(t_printf *vars, void *digit);
int				ft_h_unsd(t_printf *vars, void *digit);
int				ft_hx(t_printf *vars, void *digit);
int				ft_ho(t_printf *vars, void *digit);
int				ft_hp(t_printf *vars, void *digit);
char			*ft_stdup(const char *source);
int				ft_str(char *str, int precision);
char			ft_wchar(wchar_t len);
int				ft_wstr(wchar_t *wstr, int precision);
int				ft_output(t_printf *vars, va_list ap);
int				ft_conversion(char **format, va_list ap);
char			ft_strchr_a(char *str, int c);
int				ft_atoi_a(char **str);
int				ft_percent(t_printf *vars, char c);
void			ft_strdel(char **str);
size_t				ft_strlen(const char *s);

#endif
