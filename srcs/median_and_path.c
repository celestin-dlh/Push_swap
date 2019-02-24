/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_and_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:04:09 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/23 13:08:07 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			find_shortest_way(int max, t_dlist *pile)
{
	t_node	*node;
	int		rotate;
	int		reverse;

	node = pile->begin;
	rotate = 0;
	reverse = 0;
	while (node->value != max)
	{
		rotate++;
		node = node->next;
	}
	node = pile->end;
	while (node->value != max)
	{
		reverse++;
		node = node->back;
	}
	if (rotate > reverse)
		return (1);
	return (0);
}

int			define_median(t_dlist *dlist)
{
	int nb;

	nb = 10;
	if (dlist->length < 50)
		nb = 2;
	else if (dlist->length < 150)
		nb = 3;
	else if (dlist->length < 600)
		nb = 8;
	return (nb);
}

int			median_finder(t_dlist *dlist)
{
	size_t	i;
	int		value;
	int		median;
	t_node	*node;
	t_node	*node_temp;

	median = define_median(dlist);
	node = dlist->begin;
	while (node)
	{
		value = node->value;
		node_temp = dlist->begin;
		i = 0;
		while (node_temp)
		{
			if (value > node_temp->value)
				i++;
			node_temp = node_temp->next;
		}
		if (i == (dlist->length / median))
			return (value);
		node = node->next;
	}
	return (value);
}
