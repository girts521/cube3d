/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:16:43 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 12:37:10 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	write(fd, &"0123456789"[num % 10], 1);
}

/// iterative

// static unsigned int	ft_n_digits(int n)
// {
// 	unsigned int	d;
// 	unsigned int	num;

// 	d = 0;
// 	if (n == 0)
// 		return (1);
// 	num = n;
// 	while (num > 0)
// 	{
// 		num /= 10;
// 		d++;
// 	}
// 	return (d);
// }

// static unsigned int	ft_pow(unsigned int num, unsigned int d)
// {
// 	while (d-- != 1)
// 		num /= 10;
// 	return (num);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	unsigned int	num;
// 	unsigned int	d;

// 	if (n < 0)
// 	{
// 		n = n * -1;
// 		write(fd, "-", 1);
// 	}
// 	num = n;
// 	d = ft_n_digits(num);
// 	while (d != 0)
// 	{
// 		write(fd, &"0123456789"[ft_pow(num, d) % 10], 1);
// 		d--;
// 	}
// }
