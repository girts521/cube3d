/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:05:29 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 19:13:55 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	ft_shift_d_any(int num, int d, int base)
{
	while (d-- != 1)
		num /= base;
	return (num);
}

static unsigned int	ft_n_digits_any(int n, int base)
{
	unsigned int	d;
	unsigned int	num;

	d = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		d++;
	}
	num = n;
	while (num > 0)
	{
		num /= base;
		d++;
	}
	return (d);
}

int	ft_putbase(int n, char *set, int base)
{
	unsigned int	d;
	int				len;

	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	d = ft_n_digits_any(n, base);
	len = d;
	while (d != 0)
		write(1, set + ft_shift_d_any(n, d--, base) % base, 1);
	return (len);
}
