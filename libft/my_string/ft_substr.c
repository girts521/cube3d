/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:20:54 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:04:01 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	i2;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i <= len)
		i++;
	if (s[start + i] == '\0' && i - 1 != len)
		i++;
	res = (char *)malloc(i * sizeof(char));
	if (!res)
		return (NULL);
	i2 = 0;
	while (i2 < i - 1)
	{
		res[i2] = s[start + i2];
		i2++;
	}
	res[i2] = '\0';
	return (res);
}
