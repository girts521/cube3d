/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:51 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:23:42 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(unsigned int *i, size_t n, t_flags *flags)
{
	int	d;

	(*i)++;
	if (n == 0)
		d = 5;
	else
		d = ft_n_d_hex(n) + 2;
	if (flags->left_align == 0)
	{
		ft_padding(flags, ' ', d);
		*flags->len += ft_putpointer(n);
	}
	else
	{
		*flags->len += ft_putpointer(n);
		ft_padding(flags, ' ', d);
	}
}
