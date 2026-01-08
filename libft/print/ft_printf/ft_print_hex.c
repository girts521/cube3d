/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:43:49 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:28:38 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_left(unsigned int n, t_flags *f, char *s, unsigned int d)
{
	char	*prefix;
	char	pad;

	if (f->prec_0 || f->precision)
		pad = ' ';
	else
		pad = f->zero_pad;
	if (n == 0)
		prefix = "";
	else if (s[15] == 'f')
		prefix = "0x";
	else if (s[15] == 'F')
		prefix = "0X";
	if (f->hash_prefix && (pad == '0' || (f->precision >= (int)d
				&& f->precision >= f->width)))
		*f->len += ft_putstr(prefix);
	if (f->precision >= f->width)
		ft_precision_num(f, d);
	ft_padding(f, pad, ft_max(d, f->precision) + (f->hash_prefix * 2));
	if (f->hash_prefix && pad != '0'
		&& (f->precision == 0 || f->precision < f->width))
		*f->len += ft_putstr(prefix);
	if (f->precision < f->width)
		ft_precision_num(f, d);
	*f->len += ft_putbase_uns(n, s, 16);
}

static void	ft_right(unsigned int n, t_flags *f, char *s, unsigned int d)
{
	char	*prefix;

	if (n == 0)
		prefix = "";
	else if (s[15] == 'f')
		prefix = "0x";
	else if (s[15] == 'F')
		prefix = "0X";
	if (f->hash_prefix)
		*f->len += ft_putstr(prefix);
	ft_precision_num(f, d);
	*f->len += ft_putbase_uns(n, s, 16);
	ft_padding(f, ' ', (f->hash_prefix * 2)
		+ ft_max(d, f->precision));
}

static unsigned int	ft_n_d_any(unsigned int n, int base)
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

void	ft_print_hex(unsigned int *i, unsigned int n, t_flags *f, char c)
{
	char			*s;
	unsigned int	d;

	(*i)++;
	if (n == 0 && f->prec_0)
	{
		ft_padding(f, ' ', 0);
		return ;
	}
	if (c == 'x')
		s = "0123456789abcdef";
	else
		s = "0123456789ABCDEF";
	d = ft_n_d_any(n, 16);
	if (f->left_align == 0)
		ft_left(n, f, s, d);
	else
		ft_right(n, f, s, d);
}
