/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:55:59 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/06 16:18:29 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static int	ft_err(char *error_flag)
{
	*error_flag = 1;
	return (0);
}

int	ft_atoi_err(const char *s, char *error_flag)
{
	int			i;
	int			sign;
	long long	temp;

	i = 0;
	sign = 1;
	temp = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign = sign * -1;
	}
	if (s[i] == '\0')
		return (ft_err(error_flag));
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		temp = temp * 10 + (s[i++] - 48);
		if (sign * temp > INT_MAX || sign * temp < INT_MIN)
			return (ft_err(error_flag));
	}
	if (s[i] != '\0' || i == 0)
		return (ft_err(error_flag));
	return ((int)(temp * sign));
}
// accounts for "", trimming removed for now
