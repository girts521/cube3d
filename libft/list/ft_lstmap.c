/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:15:41 by afruhauf          #+#    #+#             */
/*   Updated: 2024/11/17 00:19:16 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*pl_h;
	t_list	*start_res;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (NULL);
	start_res = res;
	lst = lst->next;
	while (lst != NULL)
	{
		pl_h = ft_lstnew(f(lst->content));
		if (!pl_h)
		{
			ft_lstclear(&start_res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, pl_h);
		lst = lst->next;
	}
	return (res);
}
// without deleting whole res list??

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*res;
// 	t_list	*pl_h;

// 	if (!(res = ft_lstnew(f(lst->content))))
// 		return (NULL);
// 	lst = lst->next;
// 	while (lst != NULL)
// 	{
// 		if (!(pl_h = ft_lstnew(f(lst->content))))
// 		{
// 			ft_lstclear(&res, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&res, pl_h);
// 		lst = lst->next;
// 	}
// 	return (res);
// }
