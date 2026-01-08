/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:54:20 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/16 23:19:58 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	bytes;

	if (size && nmemb > ((size_t) -1) / size)
		return (NULL);
	bytes = nmemb * size;
	p = malloc(bytes);
	if (!p)
		return (NULL);
	ft_memset(p, 0, bytes);
	return (p);
}
// max size_t on 64 bit system: 18446744073709551615
//-> /2   9223372036854775807ULL
// orig calloc devides by 2 apparantly??
// AH cause calloc implies an Array -> min 2 elemts
//malloc fails, so the overflow guardrail should be needed
// cause it might work due to chance

// static size_t	ft_maxsizet(void)
// {
// 	if (sizeof(void*) == 8)
// 		return ((size_t) 18446744073709551615ULL);
// 	if (sizeof(void*) == 4)
// 		return ((size_t) 4294967295U);
// 	else
// 		return (1);
// }

// if (nmemb == 0 || size == 0)
	// 	return (NULL);
	// if (nmemb > (ft_maxsizet() / 2) / size)
	// 	return (NULL);
