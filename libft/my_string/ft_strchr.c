/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:18:03 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:18 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
// cast to unsigned char better
// should wraps around on minus num -> therefor cast to unsigned char
// while (c >= 256)
		//c -= 256;
