/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:58 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 20:11:49 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../print.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	zero_pad;
	int	left_align;
	int	show_plus;
	int	space_before;
	int	hash_prefix;
	int	width;
	int	precision;
	int	prec_0;
	int	*len;
}		t_flags;

int				ft_handle_flags(unsigned int *i, const char *s, va_list *pargs,
					int *len);
void			ft_print(unsigned int *i, const char *s, va_list *pargs,
					t_flags *f);
void			ft_print_num(unsigned int *i, va_list *pargs, t_flags *f);
void			ft_print_num_uns(unsigned int *i, va_list *pargs, t_flags *f);
void			ft_numplus(unsigned int num, t_flags *f);
void			ft_print_p(unsigned int *i, size_t n, t_flags *f);
void			ft_print_hex(unsigned int *i, unsigned int n, t_flags *f,
					char c);
void			ft_print_str(unsigned int *i, char *s, t_flags *f);
void			ft_print_char(unsigned int *i, char c, t_flags *f);
void			ft_padding(t_flags *f, char c, int pad_mod);
void			ft_precision_num(t_flags *f, int prec_mod);
void			ft_init_flags(t_flags *f, int *len);
void			ft_parse_flags(unsigned int *i, const char *s, t_flags	*f);
int				ft_isflag(const char c);
int				ft_isdesc(char c);
void			ft_check_prec_0(t_flags	*f, const char *s);

#endif
