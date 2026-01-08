/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:31:28 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:31:38 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_char.h"

int	ft_ischars(int c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}
