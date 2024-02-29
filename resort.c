/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:33 by asabir            #+#    #+#             */
/*   Updated: 2024/02/29 16:36:37 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_value_and_rank(t_stack *pile, int *min, int *min_final_rank)
{
	t_node	*temp;

	temp = pile->head;
	*min = temp->value;
	*min_final_rank = temp->final_rank;
	while (temp)
	{
		if (*min > temp->value)
		{
			*min = temp->value;
			*min_final_rank = temp->final_rank;
		}
		temp = temp->next;
	}
}

void	resort(t_stack *pile)
{
	int	min;
	int	min_final_rank;
	int	size;

	size = ft_lstsize(pile);
	find_min_value_and_rank(pile, &min, &min_final_rank);
	if (!less_median(min_final_rank, size))
	{
		while (min != pile->head->value)
			rra(pile);
	}
	else
	{
		while (min != pile->head->value)
			ra(pile);
	}
}
