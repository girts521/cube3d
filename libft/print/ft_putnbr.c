/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:07:41 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/20 23:46:06 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putnbr(int n)
{
	unsigned int	num;
	unsigned int	d;
	int				len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		len += 1;
	}
	num = n;
	d = ft_n_d_uns(num);
	len += d;
	while (d != 0)
	{
		write(1, &"0123456789"[ft_shift_d(num, d) % 10], 1);
		d--;
	}
	return (len);
}
