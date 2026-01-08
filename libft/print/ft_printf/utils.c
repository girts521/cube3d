/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:17 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 19:32:12 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(const char c)
{
	if (c == '0' || c == '-' || c == '+' || c == '#' || c == ' ' || c == '.')
		return (1);
	return (0);
}

int	ft_isdesc(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%' || c == 'i')
		return (1);
	return (0);
}

void	ft_init_flags(t_flags *flags, int *len)
{
	flags->zero_pad = ' ';
	flags->left_align = 0;
	flags->show_plus = 0;
	flags->space_before = 0;
	flags->hash_prefix = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->prec_0 = 0;
	flags->len = len;
}

static int	ft_num(unsigned int *i, const char *s, int *len)
{
	int	n;

	n = 0;
	while ((s[*i] && ft_isdigit(s[*i])))
	{
		n = (n * 10) + (s[(*i)++] - 48);
		*len -= 1;
	}
	return (n);
}

void	ft_parse_flags(unsigned int *i, const char *s, t_flags	*flags)
{
	while (ft_isflag(s[*i]) && s[*i] != '.')
	{
		if (s[*i] == '0')
			flags->zero_pad = '0';
		else if (s[*i] == '-')
			flags->left_align = 1;
		else if (s[*i] == '+')
			flags->show_plus = 1;
		else if (s[*i] == ' ')
			flags->space_before = 1;
		else if (s[*i] == '#')
			flags->hash_prefix = 1;
		(*i)++;
		*flags->len -= 1;
	}
	if (ft_isdigit(s[*i]))
		flags->width = ft_num(i, s, flags->len);
	if (s[(*i)] == '.')
	{
		(*i)++;
		ft_check_prec_0(flags, s + *i);
		flags->precision = ft_num(i, s, flags->len);
		*flags->len -= 1;
	}
}
