/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:02:21 by afruhauf          #+#    #+#             */
/*   Updated: 2024/12/09 20:14:37 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../libft.h"

size_t	ft_putstr(char *s);
size_t	ft_putnstr(char *s, size_t n);
int		ft_putbase(int n, char *set, int base);
int		ft_putbase_uns(unsigned int n, const char *set, int base);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_uns(unsigned int n);
int		ft_putpointer(size_t p);

int		ft_printf(const char *s, ...);

#endif
