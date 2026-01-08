/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:54 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:23:50 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_param(unsigned int *i, const char *s, va_list *pargs, int *len);
static int	ft_insert(const char c, va_list *pargs, int *len);

int	ft_printf(const char *s, ...)
{
	unsigned int	i;
	int				len;
	va_list			pargs;

	if (!s)
		return (-1);
	va_start(pargs, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
			write(1, &s[i++], 1);
		else
		{
			if (ft_param(&i, s, &pargs, &len))
				return (-1);
		}
	}
	va_end(pargs);
	return (len + i);
}

static int	ft_param(unsigned int *i, const char *s, va_list *pargs, int *len)
{
	if (ft_isflag(s[++(*i)]) || ft_isdigit(s[*i]))
	{
		if (ft_handle_flags(i, s, pargs, len))
			return (1);
	}
	else
		if (ft_insert(s[(*i)++], pargs, len))
			return (1);
	*len -= 1;
	return (0);
}

static int	ft_insert(const char c, va_list *pargs, int *len)
{
	*len -= 1;
	if (c == 'c')
		*len += ft_putchar(va_arg(*pargs, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(*pargs, char *));
	else if (c == 'p')
		*len += ft_putpointer((size_t)va_arg(*pargs, void *));
	else if (c == 'd' || c == 'i')
		*len += ft_putnbr(va_arg(*pargs, int));
	else if (c == 'u')
		*len += ft_putnbr_uns(va_arg(*pargs, unsigned int));
	else if (c == 'x')
		*len += ft_putbase_uns(va_arg(*pargs, unsigned int),
				"0123456789abcdef", 16);
	else if (c == 'X')
		*len += ft_putbase_uns(va_arg(*pargs, unsigned int),
				"0123456789ABCDEF", 16);
	else if (c == '%')
		*len += ft_putchar('%');
	else if (!ft_isdesc(c))
		return (1);
	return (0);
}
