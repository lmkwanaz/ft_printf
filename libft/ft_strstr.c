/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 06:21:43 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/06/13 12:38:08 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t slen;

	slen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
		if (!ft_memcmp(haystack++, needle, slen))
			return ((char *)haystack - 1);
	return (0);
}
