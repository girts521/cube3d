/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:29:46 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/04 19:39:18 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_add_node(t_buff	**n_current, t_buff **n_start);
static char		*ft_line(t_buff *n_start, t_buff *n_current, char *error_flag,
					char with_n);
static t_buff	*ft_remainder_node(char *new_l, ssize_t *error_flag);
void			ft_check_remainder_node(t_buff *n_current, char **new_l);

char	*get_next_line(int fd, char *error_flag, char with_n)
{
	char			*new_l;
	static t_buff	*n_current = NULL;
	t_buff			*n_start;
	ssize_t			b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_start = n_current;
	b = 1;
	ft_check_remainder_node(n_current, &new_l);
	while (new_l == NULL && b > 0)
	{
		if (ft_add_node(&n_current, &n_start))
			return (ft_clbuff_err(&n_start, &n_current, error_flag));
		b = read(fd, n_current->s, BUFFER_SIZE);
		if (b < 0)
			return (ft_clbuff_err(&n_start, &n_current, error_flag));
		n_current->s[b] = '\0';
		new_l = ft_strchr(n_current->s, '\n');
	}
	n_current = ft_remainder_node(new_l, &b);
	if (!n_current && b == -1)
		return (ft_clbuff_err(&n_start, &n_current, error_flag));
	return (ft_line(n_start, n_current, error_flag, with_n));
}
// b also used as error_flag in ft_remainder_node

static int	ft_add_node(t_buff	**n_current, t_buff **n_start)
{
	t_buff	*node;

	node = (t_buff *)malloc(sizeof(t_buff));
	if (!node)
		return (1);
	if (*n_current == NULL)
		*n_start = node;
	else
		(*n_current)->next = node;
	*n_current = node;
	node->next = NULL;
	return (0);
}
// add back and move head with it, but keep the start pointer for traversal

static char	*ft_line(t_buff *n_start, t_buff *n_current, char *error_flag,
						char with_n)
{
	char	*res;
	size_t	i;
	size_t	i2;
	t_buff	*n_copy;
	size_t	len;

	n_copy = n_start;
	len = ft_node_slen(n_start, with_n);
	if (len == 0 && (!n_start || (n_start->s[0] == '\0'
				&& !ft_strchr(n_start->s, '\n'))))
		return (ft_clbuff(&n_copy, &n_copy));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (ft_clbuff_err(&n_copy, &n_current, error_flag));
	i2 = 0;
	while (n_start != NULL && i2 < len)
	{
		i = 0;
		while (n_start->s[i] && i2 < len)
			res[i2++] = n_start->s[i++];
		n_start = n_start->next;
	}
	ft_clbuff(&n_copy, &n_copy);
	res[i2] = '\0';
	return (res);
}
// should iterate up to len cause case with no \n

static t_buff	*ft_remainder_node(char *new_l, ssize_t *error_flag)
{
	t_buff	*node;
	size_t	i;

	if (new_l == NULL || new_l[1] == '\0')
		return (NULL);
	new_l++;
	node = (t_buff *)malloc(sizeof(t_buff));
	if (!node)
	{
		*error_flag = -1;
		return (NULL);
	}
	i = 0;
	while (new_l[i])
	{
		node->s[i] = new_l[i];
		i++;
	}
	node->s[i] = '\0';
	node->next = NULL;
	return (node);
}
//new rest node without linking to list, casue not needed it

void	ft_check_remainder_node(t_buff *n_current, char **new_l)
{
	*new_l = NULL;
	if (n_current != NULL)
		*new_l = ft_strchr(n_current->s, '\n');
}
// test nodes
// while(n_start != NULL)
// {
// 	printf("\n-node: %s", n_start->s);
// 	n_start = n_start->next;
// }
//
