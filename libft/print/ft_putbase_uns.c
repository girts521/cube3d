/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:06:41 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/07 22:10:12 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static unsigned int	ft_shift_d_any(unsigned int num, int d, int base)
{
	while (d-- != 1)
		num /= base;
	return (num);
}

static unsigned int	ft_n_digits_any(unsigned int n, int base)
{
	unsigned int	d;
	unsigned int	num;

	d = 0;
	if (n == 0)
		return (1);
	num = n;
	while (num > 0)
	{
		num /= base;
		d++;
	}
	return (d);
}

int	ft_putbase_uns(unsigned int n, const char *set, int base)
{
	unsigned int	d;
	int				len;

	d = ft_n_digits_any(n, base);
	len = d;
	while (d != 0)
		write(1, &(set[ft_shift_d_any(n, d--, base) % base]), 1);
	return (len);
}

// recursive
// void	ft_printbase(int n, char  *set, int base)
// {
// 	if (n >= base)
// 		ft_printbase(n / base, set, base);
// 	write(1, set[n % base], 1);
// }
// //"0123456789abcdef"
