/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:07:25 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 19:13:34 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putnbr_uns(unsigned int n)
{
	unsigned int	d;
	int				len;

	d = ft_n_d_uns(n);
	len = d;
	while (d != 0)
	{
		write(1, &"0123456789"[ft_shift_d(n, d) % 10], 1);
		d--;
	}
	return (len);
}
