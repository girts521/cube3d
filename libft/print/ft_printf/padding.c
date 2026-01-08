/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:07 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:23:59 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(t_flags *flags, char c, int pad_mod)
{
	int		n;

	n = flags->width;
	if (n > pad_mod)
	{
		n -= pad_mod;
		*flags->len += n;
		while (n-- != 0)
			write(1, &c, 1);
	}
}

void	ft_precision_num(t_flags *flags, int prec_mod)
{
	int	n;

	n = flags->precision;
	if (n > prec_mod)
	{
		n -= prec_mod;
		*flags->len += n;
		while (n-- != 0)
			write(1, &"0", 1);
	}
}
