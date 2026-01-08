/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:43:45 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:23:09 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_flags(unsigned int *i, const char *s, va_list *pargs, int *len)
{
	t_flags	f;

	ft_init_flags(&f, len);
	ft_parse_flags(i, s, &f);
	if (!ft_isdesc(s[*i]))
		return (1);
	ft_print(i, s, pargs, &f);
	return (0);
}

void	ft_print(unsigned int *i, const char *s, va_list *pargs, t_flags *f)
{
	*f->len -= 1;
	if (s[*i] == 'd' || s[*i] == 'i')
		ft_print_num(i, pargs, f);
	else if (s[*i] == 'u')
		ft_print_num_uns(i, pargs, f);
	else if (s[*i] == 'p')
		ft_print_p(i, (size_t)va_arg(*pargs, void *), f);
	else if (s[*i] == 'x' || s[*i] == 'X')
		ft_print_hex(i, va_arg(*pargs, unsigned int), f, s[*i]);
	else if (s[*i] == 's')
		ft_print_str(i, va_arg(*pargs, char *), f);
	else if (s[*i] == 'c')
		ft_print_char(i, va_arg(*pargs, int), f);
	else if (s[*i] == '%')
	{
		*f->len += ft_putchar('%');
		(*i)++;
	}
}

void	ft_print_num_uns(unsigned int *i, va_list *pargs, t_flags *f)
{
	unsigned int	num;

	(*i)++;
	num = va_arg(*pargs, unsigned int);
	if (num == 0 && f->prec_0)
	{
		ft_padding(f, ' ', 0);
		return ;
	}
	ft_numplus(num, f);
}

void	ft_check_prec_0(t_flags	*f, const char *s)
{
	if (!(*s >= '0' && *s <= '9'))
	{
		f->prec_0 = 1;
		return ;
	}
	while (*s == '0')
		s++;
	if (!(*s >= '1' && *s <= '9'))
		f->prec_0 = 1;
}

// void	ft_handle_num_prec_0(t_flags *f)
// {
// 	ft_padding(f, ' ', 0);
// }
