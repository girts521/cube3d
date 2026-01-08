/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:10 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:31:35 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_left(char *s, t_flags *flags, int s_len)
{
	if (s == NULL && flags->precision < 6 && flags->precision != 0)
		ft_padding(flags, ' ', 0);
	else if (flags->precision)
		ft_padding(flags, ' ', ft_min(s_len, flags->precision));
	else
		ft_padding(flags, ' ', s_len);
	if (flags->precision || flags->prec_0)
		*flags->len += ft_putnstr(s, flags->precision);
	else
		*flags->len += ft_putstr(s);
}

static void	ft_right(char *s, t_flags *flags, int s_len)
{
	if (flags->precision || flags->prec_0)
		*flags->len += ft_putnstr(s, flags->precision);
	else
		*flags->len += ft_putstr(s);
	if (s == NULL && flags->precision < 6 && flags->precision != 0)
		ft_padding(flags, ' ', 0);
	else if (flags->precision)
		ft_padding(flags, ' ', ft_min(s_len, flags->precision));
	else
		ft_padding(flags, ' ', s_len);
}

void	ft_print_str(unsigned int *i, char *s, t_flags *flags)
{
	int	s_len;

	s_len = (int)ft_strlen(s);
	if (!s_len && s == NULL && !flags->prec_0)
		s_len = 6;
	else if (flags->prec_0)
		s_len = 0;
	(*i)++;
	if (flags->left_align == 0)
		ft_left(s, flags, s_len);
	else
		ft_right(s, flags, s_len);
}

void	ft_print_char(unsigned int *i, char c, t_flags *flags)
{
	(*i)++;
	if (flags->left_align == 0)
	{
		ft_padding(flags, ' ', 1);
		*flags->len += ft_putchar(c);
	}
	else
	{
		*flags->len += ft_putchar(c);
		ft_padding(flags, ' ', 1);
	}
}
