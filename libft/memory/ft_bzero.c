/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:53:58 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/16 23:18:01 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*st;
	size_t			i;

	st = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		st[i] = '\0';
		i++;
	}
}
