/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:51:49 by asabir            #+#    #+#             */
/*   Updated: 2024/03/08 17:56:39 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_node	*find_highest_rank_t_node(t_stack *pile)
{
	t_node	*highest;
	int		max;
	t_node	*current;

	highest = NULL;
	max = INT_MIN;
	current = pile->head;
	while (current != NULL)
	{
		if (current->value == INT_MIN)
			current->order = 1;
		if (current->value > max && current->order == -1)
		{
			max = current->value;
			highest = current;
		}
		current = current->next;
	}
	return (highest);
}

void	set_order(t_stack *pile)
{
	int		size;
	t_node	*highest;

	size = ft_lstsize(pile);
	while (size)
	{
		highest = find_highest_rank_t_node(pile);
		if (highest)
			highest->order = size;
		size--;
	}
}
