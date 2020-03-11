/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:08:18 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/08/12 07:19:50 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *alloc;

	alloc = malloc(size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, size);
	return (alloc);
}
