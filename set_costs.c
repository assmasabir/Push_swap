/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:41:57 by asabir            #+#    #+#             */
/*   Updated: 2024/02/29 16:41:08 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	less_median_by_pos(int pos, int size)
{
	int	median;

	median = size / 2;
	if (pos <= median)
		return (1);
	else
		return (0);
}

void	set_cost(t_stack *a, t_stack *b)
{
	int		size_of_a;
	int		size_of_b;
	t_node	*tempa;
	t_node	*tempb;

	size_of_a = ft_lstsize(a);
	size_of_b = ft_lstsize(b);
	tempa = a->head;
	tempb = b->head;
	while (tempa)
	{
		if (less_median_by_pos(tempa->position, size_of_a))
			tempa->cost = tempa->position;
		else
			tempa->cost = -(size_of_a - tempa->position);
		tempa = tempa->next;
	}
	while (tempb)
	{
		if (less_median_by_pos(tempb->position, size_of_b))
			tempb->cost = tempb->position;
		else
			tempb->cost = -(size_of_b - tempb->position);
		tempb = tempb->next;
	}
}

int	cost_sum(int cost_a, int cost_b)
{
	int	sum;

	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	sum = cost_a + cost_b;
	return (sum);
}

t_node	*find_node_with_smallest_cost(t_stack *b)
{
	t_node	*temp;
	int		smallest_cost;
	t_node	*t_node_with_smallest_cost;
	int		current_cost;

	temp = b->head;
	smallest_cost = INT_MAX;
	t_node_with_smallest_cost = NULL;
	while (temp)
	{
		current_cost = cost_sum(temp->cost, temp->cible->cost);
		if (current_cost < smallest_cost)
		{
			smallest_cost = current_cost;
			t_node_with_smallest_cost = temp;
		}
		temp = temp->next;
	}
	return (t_node_with_smallest_cost);
}
