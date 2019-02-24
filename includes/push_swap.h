/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:59:13 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/21 10:47:46 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_node
{
	int				value;
	struct s_node	*back;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlist
{
	size_t			length;
	t_node			*begin;
	t_node			*end;
}					t_dlist;

int					checker(t_dlist *pile_a, t_dlist *pile_b);
t_dlist				*new_dlist(void);
t_dlist				*insert_end(t_dlist *dlist, int data);
void				free_dlist(t_dlist *dlist);
t_dlist				*fill_dlist(int argc, char **argv);
t_dlist				*create_tab_spliter(char **argv);
int					*create_tab(int argc, char **argv, int start);
void				swap(t_dlist *dlist);
void				rotate(t_dlist *dlist);
void				reverse_rotate(t_dlist *dlist);
void				push(t_dlist *src, t_dlist *dst);
int					find_shortest_way(int max, t_dlist *pile);
int					median_finder(t_dlist *dlist);
int					special_sort(t_dlist *pile_a);
void				selection_sort(t_dlist *pile_a, t_dlist *pile_b);
void				sorting(t_dlist *pile_a, t_dlist *pile_b);
void				quick_sort_summary(t_dlist *pile_a, t_dlist *pile_b);
int					find_shortest_way(int max, t_dlist *pile);
int					max_value_list(t_dlist *dlist);
int					is_sort_croissant(t_dlist *pile_a);
int					is_sort_decroissant(t_dlist *pile_a);

#endif
