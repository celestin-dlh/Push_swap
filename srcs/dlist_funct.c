/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:01:30 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/19 11:39:03 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist		*new_dlist(void)
{
	t_dlist *dlist;

	dlist = malloc(sizeof(t_dlist));
	if (dlist != NULL)
	{
		dlist->length = 0;
		dlist->begin = NULL;
		dlist->end = NULL;
	}
	return (dlist);
}

t_dlist		*insert_end(t_dlist *dlist, int data)
{
	t_node	*dlist_node;

	if (!(dlist_node = malloc(sizeof(*dlist_node))))
		return (NULL);
	dlist_node->value = data;
	dlist_node->next = NULL;
	if (dlist->end == NULL)
	{
		dlist->begin = dlist_node;
		dlist->end = dlist_node;
		dlist_node->back = NULL;
	}
	else
	{
		dlist->end->next = dlist_node;
		dlist_node->back = dlist->end;
		dlist->end = dlist_node;
	}
	dlist->length++;
	return (dlist);
}

void		free_dlist(t_dlist *dlist)
{
	t_node *node;
	t_node *del;

	node = dlist->begin;
	while (node)
	{
		del = node;
		node = node->next;
		free(del);
	}
	free(dlist);
	dlist = NULL;
}
