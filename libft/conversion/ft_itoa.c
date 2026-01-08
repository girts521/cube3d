/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:12:19 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:04:36 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	skip_0;
	unsigned int	len;
	unsigned int	num;

	len = ft_n_digits(n);
	res = (char *)malloc((len * sizeof(char)) + 1);
	if (!res)
		return (NULL);
	skip_0 = 0;
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
		skip_0++;
	}
	num = n;
	res[len] = '\0';
	while (0 + skip_0 < len)
	{
		res[len - 1] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	return (res);
}
