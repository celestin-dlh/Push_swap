/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_d_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:01:12 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/19 11:50:37 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		valid_format(char *str)
{
	int		nb;
	char	*nb_str;

	nb = ft_atoi(str);
	if (!(nb_str = ft_itoa(nb)))
		return (-1);
	if (ft_strcmp(str, nb_str) != 0)
	{
		free(nb_str);
		return (-1);
	}
	free(nb_str);
	return (0);
}

int		check_double_int(int *tab, int max)
{
	int		i;
	int		temp;
	int		nb;

	i = 0;
	while (i < max)
	{
		temp = i;
		nb = tab[i];
		while (temp < max)
		{
			temp++;
			if (nb == tab[temp])
				return (-1);
		}
		i++;
	}
	return (0);
}

int		*create_tab(int argc, char **argv, int start)
{
	int		i;
	int		j;
	int		*tab;

	i = start;
	j = 0;
	if (!((tab = (int*)malloc(sizeof(int) * argc))))
		return (NULL);
	while (i < argc)
	{
		if (valid_format(argv[i]) == -1)
		{
			free(tab);
			return (NULL);
		}
		tab[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (check_double_int(tab, i - 1) == -1)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

t_dlist	*fill_dlist(int argc, char **argv)
{
	t_dlist		*dlist;
	int			*tab;
	int			i;

	if (argc == 2)
	{
		if (!(dlist = create_tab_spliter(argv)))
			return (NULL);
		return (dlist);
	}
	else if ((tab = (create_tab(argc, argv, 1))) == NULL)
		return (NULL);
	i = 0;
	if (!(dlist = new_dlist()))
	{
		free(tab);
		return (NULL);
	}
	while (i < argc - 1)
	{
		dlist = insert_end(dlist, tab[i]);
		i++;
	}
	free(tab);
	return (dlist);
}
