/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:30:04 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:45:21 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_char.h"

static int	ft_top(int c, char t)
{
	if (t == 'a')
		return (ft_isalpha(c));
	if (t == 'b')
		return (ft_isbinary(c));
	if (t == 'c')
		return (ft_isascii(c));
	if (t == 'd')
		return (ft_isdigit(c));
	if (t == 'h')
		return (ft_ishex(c));
	if (t == 'l')
		return (ft_islow(c));
	return (0);
}

static int	ft_bottom(int c, char t)
{
	if (t == 'p')
		return (ft_isprint(c));
	if (t == 's')
		return (ft_isspace(c));
	if (t == 'u')
		return (ft_isup(c));
	if (t == 'x')
		return (ft_isalnum(c));
	return (0);
}

int	ft_checkchar(int c, char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] < 'p')
		{
			if (ft_top(c, set[i]))
				return (1);
		}
		else
		{
			if (ft_bottom(c, set[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
