/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:32:36 by afruhauf          #+#    #+#             */
/*   Updated: 2025/01/04 19:37:56 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../file.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buff
{
	char			s[BUFFER_SIZE + 1];
	struct s_buff	*next;
}					t_buff;

char	*ft_strchr(const char *s, int c);
size_t	ft_node_slen(t_buff *n_start);
void	*ft_clbuff_err(t_buff **lst, t_buff**lst_2, char *error_flag);
void	*ft_clbuff(t_buff **lst, t_buff **lst_2);

#endif
