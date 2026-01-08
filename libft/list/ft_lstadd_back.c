/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:12:38 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 00:18:49 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
		ft_lstlast(*lst)->next = new;
}

// /// with temp variable
// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list *temp;

//     if (*lst == NULL)  // If the list is empty
//     {
//         *lst = new;
//         return;
//     }

//     temp = *lst;  // Use a temporary pointer to traverse the list

//     // Traverse to the last node
//     while (temp->next != NULL)
//         temp = temp->next;

//     // Add the new node at the end of the list
//     temp->next = new;
// }
