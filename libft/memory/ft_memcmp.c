/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:16:09 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/16 23:20:03 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
// crashes only when 1 NULL pointer
// can be seen when disabling -Wall -Wex.. flags
