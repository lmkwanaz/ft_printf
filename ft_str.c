/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:51:15 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/26 14:57:21 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             ft_str(char *str, int prec)
{
        int l;

        l = 0;
        if (str == NULL)
                return (ft_str("(null)", prec));
        while (*str != '\0' && prec--)
        {
                l = l + ft_char(*str);
				str++;
        }
        return (l);
}
