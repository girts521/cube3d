/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:20:23 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:57 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	i2;
	size_t	i3;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	i2 = ft_strlen(s1);
	while (i2 != 1 && ft_strchr(set, s1[i2 - 1]))
		i2--;
	if ((int)(i2 - i) < 0)
		i2 = i;
	res = (char *)malloc(((i2 - i) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i3 = 0;
	while (i < i2)
		res[i3++] = s1[i++];
	res[i3] = '\0';
	return (res);
}
