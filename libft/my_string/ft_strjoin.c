/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:18:40 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:30 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	i2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2])
	{
		res[i] = s2[i2];
		i++;
		i2++;
	}
	res[i] = '\0';
	return (res);
}
/// old
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;
// 	size_t	i2;
// 	char	*res;

// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	if (!(res = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
// 		return (NULL);
// 	i = 0;
// 	while (i <= len1 - 1 && len1 != 0)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	i2 = 0;
// 	while (i2 <= len2 - 1 && len2 != 0)
// 	{
// 		res[i] = s2[i2];
// 		i++;
// 		i2++;
// 	}
// 	res[i] = '\0';
// 	return(res);
// }
