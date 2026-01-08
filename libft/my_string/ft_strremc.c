/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:41:26 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/23 23:17:39 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

static unsigned int	ft_n_c(char const *s, char const *set)
{
	unsigned int	i;
	unsigned int	i2;
	unsigned int	count;

	i = 0;
	i2 = 0;
	count = 0;
	while (s[i])
	{
		while (set[i2])
		{
			if (s[i] == set[i2])
				count++;
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (count);
}

static int	ft_match(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strremc(char const *s, char const *set)
{
	unsigned int	i;
	unsigned int	i2;
	char			*res;

	i = 0;
	i2 = 0;
	res = (char *)malloc(((ft_strlen(s) - ft_n_c(s, set)) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (!ft_match(s[i], set))
			res[i2++] = s[i];
		i++;
	}
	res[i2] = '\0';
	return (res);
}
// I could create a temp arr of same size as input
// and after copy it over with the actual res size (free temp of course)
