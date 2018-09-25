/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:06:51 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 17:07:17 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;

	l = 0;
	while ((unsigned char)s1[l] && (unsigned char)s2[l] &&
			(unsigned char)s1[l] == (unsigned char)s2[l] && l < n - 1)
		l++;
	if (n)
		return ((unsigned char)s1[l] - (unsigned char)s2[l]);
	return (0);
}
