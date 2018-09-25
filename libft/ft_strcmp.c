/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 15:05:59 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 12:09:54 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int l;

	l = 0;
	while (s1[l] && (unsigned char)s2[l] == (unsigned char)s1[l])
		l++;
	return ((unsigned char)s1[l] - (unsigned char)s2[l]);
}
