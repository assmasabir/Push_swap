/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:11:16 by asabir            #+#    #+#             */
/*   Updated: 2024/03/08 17:49:11 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a != 0 && cost_b != 0)
	{
		rr(a, b, 1);
		cost_b--;
		cost_a--;
	}
	if (cost_a == 0 && cost_b > 0)
	{
		while (cost_b != 0)
		{
			rb(b, 1);
			cost_b--;
		}
	}
	if (cost_b == 0 && cost_a > 0)
	{
		while (cost_a != 0)
		{
			ra(a, 1);
			cost_a--;
		}
	}
	if (cost_a == 0 && cost_b == 0)
		push_and_update(a, b);
}

void	case_2(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a != 0 && cost_b != 0)
	{
		rrr(a, b, 1);
		update_stacks(a, b);
		cost_b++;
		cost_a++;
	}
	if (cost_a == 0 && cost_b < 0)
	{
		while (cost_b != 0)
		{
			rrb(b, 1);
			cost_b++;
		}
	}
	if (cost_b == 0 && cost_a < 0)
	{
		while (cost_a != 0)
		{
			rra(a, 1);
			cost_a++;
		}
	}
	if (cost_a == 0 && cost_b == 0)
		push_and_update(a, b);
}

void	case_3(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a != 0)
	{
		rra(a, 1);
		cost_a++;
	}
	if (cost_b > 0)
	{
		while (cost_b != 0)
		{
			rb(b, 1);
			cost_b--;
		}
		if (cost_b == 0)
			push_and_update(a, b);
	}
}

void	case_4(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a != 0)
	{
		ra(a, 1);
		cost_a--;
	}
	if (cost_b < 0)
	{
		while (cost_b != 0)
		{
			rrb(b, 1);
			cost_b++;
		}
		if (cost_b == 0)
			push_and_update(a, b);
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		cost_a;
	int		cost_b;

	while (b->head)
	{
		temp = find_node_with_smallest_cost(b);
		cost_b = temp->cost;
		cost_a = temp->cible->cost;
		if (cost_a == cost_b && cost_a == 0)
			push_and_update(a, b);
		else if (cost_a >= 0 && cost_b >= 0)
			case_1(a, b, cost_a, cost_b);
		else if (cost_a <= 0 && cost_b <= 0)
			case_2(a, b, cost_a, cost_b);
		else if (cost_a <= 0 && cost_b >= 0)
			case_3(a, b, cost_a, cost_b);
		else if (cost_b <= 0 && cost_a >= 0)
			case_4(a, b, cost_a, cost_b);
	}
}
