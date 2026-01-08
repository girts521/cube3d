/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:19:00 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:49 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	i2;

	if (needle[0] == '\0')
		return ((char *) haystack);
	i = 0;
	i2 = 0;
	while (haystack[i] && (i < len))
	{
		while (haystack[i] != needle[0] && haystack[i] && (i < len))
			i++;
		while (haystack[i] == needle[i2] && haystack[i] && (i < len))
		{
			if (needle[i2 + 1] == '\0')
				return ((char *)(haystack + (i - i2)));
			i++;
			i2++;
		}
		i -= i2 - 1;
		i2 = 0;
	}
	return (NULL);
}
