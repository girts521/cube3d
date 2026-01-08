/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:08:05 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/21 22:13:32 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

size_t	ft_putnstr(char *s, size_t n)
{
	size_t	len;

	if (!s && n >= 6)
		return (ft_putstr("(null)"));
	if (!s)
		return (0);
	len = 0;
	while (*s && n != 0)
	{
		write(1, s++, 1);
		len++;
		n--;
	}
	return (len);
}
