/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:16:24 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/16 23:20:11 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		st[i] = c;
		i++;
	}
	return (s);
}
// no protection against NULL pointer, supposed to crash
