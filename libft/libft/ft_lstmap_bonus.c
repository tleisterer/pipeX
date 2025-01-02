/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:51:00 by tleister          #+#    #+#             */
/*   Updated: 2024/10/18 10:59:25 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*temp;

	if (lst == 0)
		return (0);
	nlst = ft_lstnew(f(lst->content));
	if (nlst == 0)
		return (0);
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == 0)
			return (0);
		ft_lstadd_back(&nlst, temp);
		lst = lst->next;
	}
	return (nlst);
	del(temp);
}
