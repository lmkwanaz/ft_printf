/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:55:50 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/15 09:30:37 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		l;
	long	b;
	int		x;
	int		sign;

	l = 0;
	b = 0;
	x = 0;
	sign = 1;
	while (str[l] == 32 || (str[l] >= 9 && str[l] <= 13))
		l++;
	if (str[l] == '-')
		sign = -1;
	if (str[l] == '+' || str[l] == '-')
		l++;
	while (str[l] >= '0' && str[l] <= '9')
	{
		b = (b * 10) + (str[l++] - 48);
		x++;
	}
	if (b < 0 && sign == -1)
		return (0);
	if (b < 0 && sign == 1)
		return (-1);
	return (b * sign);
}
