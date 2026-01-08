/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:18:57 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:46 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] && i < n && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
