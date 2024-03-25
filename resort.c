/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:33 by asabir            #+#    #+#             */
/*   Updated: 2024/03/25 02:49:19 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_stack_sorted(t_stack *a)
{
	t_node	*temp;

	temp = a->head;
	while (temp && temp->next)
	{
		if (temp->value < temp->next->value)
		{
			temp = temp->next;
		}
		else
			return (0);
	}
	return (1);
}

void	find_min_value_and_rank(t_stack *pile, int *min, int *min_order)
{
	t_node	*temp;

	temp = pile->head;
	*min = temp->value;
	*min_order = temp->order;
	while (temp)
	{
		if (*min > temp->value)
		{
			*min = temp->value;
			*min_order = temp->order;
		}
		temp = temp->next;
	}
}

void	resort(t_stack *pile)
{
	int	min;
	int	min_order;
	int	size;

	size = ft_lstsize(pile);
	find_min_value_and_rank(pile, &min, &min_order);
	if (!less_median(min_order, size))
	{
		while (min != pile->head->value)
			rra(pile, 1);
	}
	else
	{
		while (min != pile->head->value)
			ra(pile, 1);
	}
}
