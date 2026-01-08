/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:16:07 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/16 23:20:01 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;
	size_t			i;

	st = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (st[i] == (unsigned char)c)
			return ((void *)&st[i]);
		i++;
	}
	return (NULL);
}
// No NULL pointer protection
