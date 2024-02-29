/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:12:56 by asabir            #+#    #+#             */
/*   Updated: 2024/02/29 13:17:27 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_rank(t_stack *pile)
{
	int		max;
	t_node	*current;

	max = pile->head->final_rank;
	current = pile->head->next;
	while (current != NULL)
	{
		if (current->final_rank > max)
			max = current->final_rank;
		current = current->next;
	}
	return (max);
}

void	three_sort(t_stack *pile)
{
	int	max;

	max = get_max_rank(pile);
	if (pile->head->final_rank == max)
	{
		ra(pile);
	}
	else if (pile->head->next->final_rank == max)
	{
		rra(pile);
	}
	if (pile->head->final_rank > pile->head->next->final_rank)
	{
		sa(pile);
	}
}
