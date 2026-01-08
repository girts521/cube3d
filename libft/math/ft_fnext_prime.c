/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnext_prime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:17 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:11:17 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	ft_fnext_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (ft_fnext_prime(nb + 1));
		i++;
	}
	return (nb);
}
