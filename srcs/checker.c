/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:42:45 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/24 12:05:58 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_ope2(char *line, t_dlist *pile_a, t_dlist *pile_b)
{
	if (ft_strcmp(line, "rr") == 0)
	{
		rotate(pile_a);
		rotate(pile_b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(pile_a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(pile_b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		reverse_rotate(pile_a);
		reverse_rotate(pile_b);
	}
	else
		return (-1);
	return (0);
}

int		check_ope(char *line, t_dlist *pile_a, t_dlist *pile_b)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(line, "sa") == 0)
		swap(pile_a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(pile_b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap(pile_a);
		swap(pile_b);
	}
	else if (ft_strcmp(line, "pa") == 0)
		push(pile_b, pile_a);
	else if (ft_strcmp(line, "pb") == 0)
		push(pile_a, pile_b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(pile_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(pile_b);
	else
		ret = check_ope2(line, pile_a, pile_b);
	return (ret);
}

int		checker(t_dlist *pile_a, t_dlist *pile_b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (check_ope(line, pile_a, pile_b) == -1)
		{
			free(line);
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		free(line);
	}
	if ((is_sort_croissant(pile_a) == 0) && pile_b->begin == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
