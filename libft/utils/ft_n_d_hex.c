/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_d_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:45:29 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/20 13:46:29 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	ft_n_d_hex(size_t n)
{
	unsigned int	d;
	unsigned long	num;

	d = 0;
	if (n == 0)
		return (1);
	num = n;
	while (num > 0)
	{
		num /= 16;
		d++;
	}
	return (d);
}
