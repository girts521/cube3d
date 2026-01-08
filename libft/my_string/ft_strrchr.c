/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:19:03 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:53 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		if (s[i - 1] == (unsigned char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
// cast to unsigned char better
// should wraps around on minus num -> therefor cast to unsigned char
// while (c >= 256)
		//c -= 256;
