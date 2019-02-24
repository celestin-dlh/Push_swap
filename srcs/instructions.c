/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:04:28 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/19 11:40:34 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		swap(t_dlist *dlist)
{
	int				temp_a;
	int				temp_b;
	t_node			*node;

	if (dlist->length < 2)
		return ;
	else
	{
		node = dlist->begin;
		temp_a = node->value;
		node = node->next;
		temp_b = node->value;
		node->value = temp_a;
		node = node->back;
		node->value = temp_b;
	}
}

void		rotate(t_dlist *dlist)
{
	t_node	*node_begin;
	t_node	*node_end;
	t_node	*node_temp;

	if (dlist->length < 2)
		return ;
	else
	{
		node_begin = dlist->begin;
		node_temp = node_begin->next;
		node_temp->back = NULL;
		dlist->begin = node_temp;
		node_end = dlist->end;
		node_end->next = node_begin;
		node_begin->back = node_end;
		node_begin->next = NULL;
		dlist->end = node_begin;
	}
}

void		reverse_rotate(t_dlist *dlist)
{
	t_node	*node_begin;
	t_node	*node_end;
	t_node	*node_temp;

	if (dlist->length < 2)
		return ;
	else
	{
		node_end = dlist->end;
		node_temp = node_end->back;
		node_temp->next = NULL;
		dlist->end = node_temp;
		node_begin = dlist->begin;
		node_begin->back = node_end;
		node_end->next = node_begin;
		node_end->back = NULL;
		dlist->begin = node_end;
	}
}

void		push_mult(t_dlist *src, t_dlist *dst)
{
	t_node	*node_src;
	t_node	*node_begin;

	node_src = src->begin;
	src->begin = node_src->next;
	node_begin = src->begin;
	node_begin->back = NULL;
	node_src->back = NULL;
	if (dst->begin == NULL)
	{
		dst->begin = node_src;
		dst->end = node_src;
		node_src->next = NULL;
	}
	else
	{
		node_src->next = dst->begin;
		dst->begin->back = node_src;
		dst->begin = node_src;
	}
}

void		push(t_dlist *src, t_dlist *dst)
{
	t_node	*node_src;
	t_node	*node_begin;

	if (src->length == 0)
		return ;
	else if (src->length == 1)
	{
		node_src = src->begin;
		src->begin = NULL;
		src->end = NULL;
		node_begin = dst->begin;
		node_src->back = NULL;
		node_src->next = node_begin;
		node_begin->back = node_src;
		dst->begin = node_src;
	}
	else
		push_mult(src, dst);
	src->length--;
	dst->length++;
}
