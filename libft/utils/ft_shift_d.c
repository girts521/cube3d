/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:53:18 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 15:22:27 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	ft_shift_d(int unsigned num, int d)
{
	while (d-- != 1)
		num /= 10;
	return (num);
}
// 1 no shift, (-> 2 shift by 1 digit)
