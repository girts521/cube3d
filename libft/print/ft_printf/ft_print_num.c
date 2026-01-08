/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:48 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:23:37 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_numminus(int num, t_flags *f);

void	ft_print_num(unsigned int *i, va_list *pargs, t_flags *f)
{
	int	num;

	(*i)++;
	num = va_arg(*pargs, int);
	if (num == 0 && f->prec_0)
	{
		ft_padding(f, ' ', 0);
		return ;
	}
	if (num < 0)
		ft_numminus(num, f);
	else
		ft_numplus(num, f);
}

static void	ft_right(unsigned int num, t_flags *f, unsigned int d)
{
	if (f->space_before && !f->show_plus)
		*f->len += ft_putchar(' ');
	if (f->show_plus)
		*f->len += ft_putchar('+');
	ft_precision_num(f, d);
	*f->len += ft_putnbr_uns(num);
	ft_padding(f, ' ', ft_max(d, f->precision)
		+ ft_max(f->space_before, f->show_plus));
}

void	ft_numplus(unsigned int num, t_flags *f)
{
	unsigned int	d;
	char			pad;

	if (f->prec_0 || f->precision)
		pad = ' ';
	else
		pad = f->zero_pad;
	d = ft_n_d_uns(num);
	if (f->left_align == 0)
	{
		if (f->space_before && !f->show_plus)
			*f->len += ft_putchar(' ');
		if (f->show_plus && f->zero_pad == '0')
			*f->len += ft_putchar('+');
		ft_padding(f, pad, ft_max(d, f->precision)
			+ ft_max(f->space_before, f->show_plus));
		if (f->show_plus && f->zero_pad != '0')
			*f->len += ft_putchar('+');
		ft_precision_num(f, d);
		*f->len += ft_putnbr_uns(num);
	}
	else
		ft_right(num, f, d);
}

static void	ft_right_minus(int num, t_flags *f, unsigned int d)
{
	write(1, &"-", 1);
	ft_precision_num(f, d);
	*f->len += ft_putnbr_uns((unsigned int)num) + 1;
	ft_padding(f, ' ', ft_max(d, f->precision) + 1);
}

static void	ft_numminus(int num, t_flags *f)
{
	unsigned int	d;
	char			pad;

	if (f->prec_0 || f->precision)
		pad = ' ';
	else
		pad = f->zero_pad;
	num *= -1;
	d = ft_n_d_uns(num);
	if (f->left_align == 0)
	{
		if (pad == '0')
			write(1, &"-", 1);
		ft_padding(f, pad,
			ft_max(d, f->precision) + 1);
		if (pad != '0')
			write(1, &"-", 1);
		ft_precision_num(f, d);
		*f->len += ft_putnbr_uns((unsigned int)num) + 1;
	}
	else
		ft_right_minus(num, f, d);
}
// space ignored, + ignored, # ignored
