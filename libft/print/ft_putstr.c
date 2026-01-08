/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:08:37 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/21 00:05:54 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

size_t	ft_putstr(char *s)
{
	size_t	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (*s)
	{
		write(1, s++, 1);
		len++;
	}
	return (len);
}
