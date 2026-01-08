/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:08:20 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/03 23:40:15 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static size_t	ft_shift_d_hex(size_t n, int d)
{
	while (d-- != 1)
		n /= 16;
	return (n);
}

int	ft_putpointer(size_t p)
{
	unsigned int	d;
	int				len;
	const char		*set;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	d = ft_n_d_hex(p);
	len = d;
	set = "0123456789abcdef";
	write(1, &"0x", 2);
	len += 2;
	while (d != 0)
		write(1, &(set[ft_shift_d_hex(p, d--) % 16]), 1);
	return (len);
}

// recursive
// int	ft_putpointer(unsigned long p)
// {
// 	if (p >= 16)
// 		ft_putpointer(p / 16);
// 	write(1, &"0123456789abcdef"[p % 16], 1);
// }
