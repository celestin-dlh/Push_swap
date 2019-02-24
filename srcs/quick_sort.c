/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:18:49 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/24 12:05:34 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			push_pile_b2(t_dlist *pile_b)
{
	int		count;
	int		max_value;

	count = 0;
	max_value = max_value_list(pile_b);
	if (find_shortest_way(max_value, pile_b) == 1)
	{
		while (pile_b->begin->value != max_value)
		{
			reverse_rotate(pile_b);
			ft_putstr("rrb\n");
			count++;
		}
	}
	else
	{
		while (pile_b->begin->value != max_value)
		{
			rotate(pile_b);
			ft_putstr("rb\n");
			count++;
		}
	}
	return (count);
}

int			push_pile_b(t_dlist *pile_a, t_dlist *pile_b)
{
	int		count;

	count = 0;
	while (pile_b->begin != NULL)
	{
		count += push_pile_b2(pile_b);
		push(pile_b, pile_a);
		ft_putstr("pa\n");
		count++;
	}
	return (count);
}

int			push_or_rotate(t_dlist *pile_a, t_dlist *pile_b, int length,
		int pivot)
{
	int		count;
	int		i;
	int		value;

	i = 0;
	count = 0;
	while (i < length)
	{
		value = pile_a->begin->value;
		if (value <= pivot)
		{
			push(pile_a, pile_b);
			ft_putstr("pb\n");
		}
		else
		{
			rotate(pile_a);
			ft_putstr("ra\n");
		}
		i++;
		count++;
	}
	return (count);
}

int			quick_sort_pile_a(t_dlist *pile_a, t_dlist *pile_b)
{
	int				pivot;
	int				i;
	int				count;
	int				length;

	count = 0;
	while (pile_a->length > 3)
	{
		pivot = median_finder(pile_a);
		i = 0;
		length = (int)pile_a->length;
		count += push_or_rotate(pile_a, pile_b, length, pivot);
	}
	return (count);
}

void		quick_sort_summary(t_dlist *pile_a, t_dlist *pile_b)
{
	int		count;

	count = 0;
	count += quick_sort_pile_a(pile_a, pile_b);
	count += special_sort(pile_a);
	count += push_pile_b(pile_a, pile_b);
}
