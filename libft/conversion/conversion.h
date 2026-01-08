/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:15:40 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/06 16:09:19 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "../libft.h"

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

int		ft_atoi_err(const char *s, char *error_flag);

#endif
