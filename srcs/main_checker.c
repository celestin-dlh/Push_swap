/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:45:09 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/19 11:07:20 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_dlist *pile_a;
	t_dlist *pile_b;

	if (argc > 1)
	{
		if ((pile_a = fill_dlist(argc, argv)) == NULL)
		{
			ft_putstr("Error\n");
			return (-1);
		}
		if ((pile_b = new_dlist()) == NULL)
		{
			ft_putstr("Error\n");
			return (-1);
		}
		checker(pile_a, pile_b);
		free_dlist(pile_a);
		free_dlist(pile_b);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
