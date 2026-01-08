/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:50:17 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/06 17:44:28 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft.h"

unsigned int	ft_n_d_uns(unsigned int n);
unsigned int	ft_n_digits(int n);
unsigned int	ft_shift_d(int unsigned num, int d);
unsigned int	ft_n_d_hex(size_t n);
int				ft_max(int x, int y);
int				ft_min(int x, int y);
int				ft_n_bits(int n);

#endif
