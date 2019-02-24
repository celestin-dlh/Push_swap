/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:07:17 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/23 11:50:43 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist		*create_tab_spliter2(int *tab, char **temp, int j)
{
	t_dlist		*dlist;
	int			i;

	i = 0;
	if (!(dlist = new_dlist()))
	{
		free(tab);
		return (NULL);
	}
	while (i < j)
	{
		free(temp[i]);
		dlist = insert_end(dlist, tab[i]);
		i++;
	}
	free(temp);
	free(tab);
	return (dlist);
}

int			*fill_tab(int j, char **temp)
{
	int		*tab;

	if (!(tab = create_tab(j, temp, 0)))
	{
		j = 0;
		while (temp[j] != '\0')
		{
			free(temp[j]);
			j++;
		}
		free(temp);
		return (NULL);
	}
	return (tab);
}

t_dlist		*create_tab_spliter(char **argv)
{
	t_dlist		*dlist;
	int			*tab;
	int			j;
	char		**temp;

	j = 0;
	if (!(temp = ft_strsplit(argv[1], ' ')) || temp[0] == NULL)
	{
		if (!temp[0])
		{
			free(temp[0]);
			free(temp);
		}
		return (NULL);
	}
	while (temp[j] != NULL)
		j++;
	if (!(tab = fill_tab(j, temp)))
		return (NULL);
	if (!(dlist = create_tab_spliter2(tab, temp, j)))
		return (NULL);
	return (dlist);
}
