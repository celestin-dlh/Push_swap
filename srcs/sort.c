/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:07:35 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/15 14:30:37 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			special_sort(t_dlist *pile_a)
{
	int		i;

	i = 0;
	while (is_sort_croissant(pile_a) == -1)
	{
		if (pile_a->begin->value > pile_a->end->value)
		{
			rotate(pile_a);
			ft_putstr("ra\n");
			i++;
		}
		else if (pile_a->begin->value > pile_a->begin->next->value)
		{
			swap(pile_a);
			ft_putstr("sa\n");
			i++;
		}
		else if (pile_a->begin->next->value > pile_a->end->value)
		{
			rotate(pile_a);
			ft_putstr("ra\n");
			i++;
		}
	}
	return (i);
}

void		sorting(t_dlist *pile_a, t_dlist *pile_b)
{
	if (is_sort_croissant(pile_a) != -1)
		return ;
	if (pile_a->length < 4)
		special_sort(pile_a);
	else
		quick_sort_summary(pile_a, pile_b);
}
