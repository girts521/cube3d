/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:18:00 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 13:03:08 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

static size_t	ft_n_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_move_mark(size_t *mark, size_t i, char const *s, char c)
{
	if (s[i] == c && (i == 0 || s[i - 1] == c))
		(*mark)++;
}

static void	ft_del_arr(char	**res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
}

static int	ft_handle_malloc(char **res, char *current_element)
{
	if (!current_element)
	{
		ft_del_arr(res);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	mark;
	size_t	i2;
	char	**res;

	i = 0;
	i2 = 0;
	mark = 0;
	res = (char **)malloc((ft_n_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (i != 0 && (s[i] == c || s[i] == '\0') && s[i - 1] != c)
		{
			res[i2] = ft_substr(s, mark, i - mark);
			if (!ft_handle_malloc(res, res[i2++]))
				return (NULL);
			mark = i + 1;
		}
		ft_move_mark(&mark, i++, s, c);
	}
	res[i2] = NULL;
	return (res);
}
//freeing all prev elements if substr fails
