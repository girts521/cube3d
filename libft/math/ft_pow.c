/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:44 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:11:44 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	ft_pow(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	res = 1;
	while (power != 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
