/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:31:53 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/04 19:39:39 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_clbuff_err(t_buff **lst, t_buff **lst_2, char *error_flag)
{
	t_buff	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	*lst_2 = NULL;
	if (error_flag)
		*error_flag = 1;
	return (NULL);
}

void	*ft_clbuff(t_buff **lst, t_buff **lst_2)
{
	t_buff	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	*lst_2 = NULL;
	return (NULL);
}

size_t	ft_node_slen(t_buff *n_start, char with_n)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (n_start != NULL)
	{
		i = 0;
		while (n_start->s[i] && n_start->s[i] != '\n')
		{
			len++;
			i++;
		}
		if (n_start->s[i] == '\n')
		{
			if (with_n)
				return (len + 1);
			return (len);
		}
		if (n_start->next == NULL)
			return (len);
		n_start = n_start->next;
	}
	return (0);
}
// size_t	ft_node_slen(t_list *n_start)
// {
// 	size_t	len;
// 	size_t	i;

// 	len = 0;
// 	i = 0;
// 	while (n_start->s[len] && n_start->s[len] != '\n')
// 		len++;
// 	if (n_start->s[len] == '\n')
// 		len++;
// 	if (n_start->next == NULL)
// 		return (len);
// 	n_start = n_start->next;
// 	while (n_start->next != NULL)
// 	{
// 		len += BUFFER_SIZE;
// 		n_start = n_start->next;
// 	}
// 	while (n_start->s[i] && n_start->s[i] != '\n')
// 		i++;
// 	if (n_start->s[i] == '\n')
// 		i++;
// 	return (len + i);
// }
