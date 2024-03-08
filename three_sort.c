/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:12:56 by asabir            #+#    #+#             */
/*   Updated: 2024/03/08 17:56:39 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_rank(t_stack *pile)
{
	int		max;
	t_node	*current;

	max = pile->head->order;
	current = pile->head->next;
	while (current != NULL)
	{
		if (current->order > max)
			max = current->order;
		current = current->next;
	}
	return (max);
}

void	three_sort(t_stack *pile)
{
	int	max;

	max = get_max_rank(pile);
	if (pile->head->order == max)
	{
		ra(pile, 1);
	}
	else if (pile->head->next->order == max)
	{
		rra(pile, 1);
	}
	if (pile->head->order > pile->head->next->order)
	{
		sa(pile, 1);
	}
}
