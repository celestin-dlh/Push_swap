/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:10:01 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/19 11:42:46 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			max_value_list(t_dlist *dlist)
{
	t_node	*node;
	int		nb;

	node = dlist->begin;
	nb = node->value;
	while (node)
	{
		node = node->next;
		if (node == NULL)
			return (nb);
		if (node->value > nb)
			nb = node->value;
	}
	return (nb);
}

int			is_sort_croissant(t_dlist *pile_a)
{
	int		i;
	t_node	*node;

	node = pile_a->begin;
	while (node)
	{
		i = node->value;
		node = node->next;
		if (node == NULL)
			return (0);
		if (i > node->value)
			return (-1);
	}
	return (-1);
}

int			is_sort_decroissant(t_dlist *pile_a)
{
	int		i;
	t_node	*node;

	node = pile_a->begin;
	while (node)
	{
		i = node->value;
		node = node->next;
		if (node == NULL)
			return (0);
		if (i < node->value)
			return (-1);
	}
	return (-1);
}
