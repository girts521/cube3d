/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:12:44 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:34:18 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_CHAR_H
# define IS_CHAR_H

# include "../libft.h"

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);

int	ft_checkchar(int c, char *set);
int	ft_ischars(int c, const char *set);
int	ft_islow(int c);
int	ft_isup(int c);
int	ft_ishex(int c);
int	ft_isspace(int c);
int	ft_isbinary(int c);

#endif
