/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:48 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/22 13:30:49 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*prev;

	if (!lst)
		return (NULL);
	new = f(lst);
	prev = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		prev->next = tmp;
		prev = prev->next;
		lst = lst->next;
	}
	return (new);
}
