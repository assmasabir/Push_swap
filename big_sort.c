/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:11:16 by asabir            #+#    #+#             */
/*   Updated: 2024/02/29 16:51:36 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stacks(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	set_final_rank(a);
	set_final_rank(b);
	set_target_t_node(a, b);
	set_cost(a, b);
}

void	big_sort(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		cost_a;
	int		cost_b;
	t_node	*tempb;

	tempb = b->head;
	while (tempb)
	{
		temp = find_node_with_smallest_cost(b);
		cost_b = temp->cost;
		cost_a = temp->cible->cost;
		if (cost_a == cost_b && cost_a == 1)
		{
			ss(a, b);
			update_stacks(a, b);
		}
		else if (cost_a == cost_b && cost_a == 0)
		{
			tempb = temp->next;
			pa(a, b);
			// show(a,b,0);
			update_stacks(a, b);
			// while (test)
			// {
			//     printf("%d -> %d\n", test->value, test->cost);
			//     test = test->next;
			// }
		}
		else if (cost_a >= 0 && cost_b >= 0)
		{
			while (cost_a != 0 && cost_b != 0)
			{
				rr(a, b);
				update_stacks(a, b);
				cost_b = temp->cost;
				cost_a = temp->cible->cost;
			}
			if (cost_a == 0 && cost_b > 0)
			{
				while (cost_b != 0)
				{
					rb(b);
					update_stacks(a, b);
					cost_b = temp->cost;
					// c'est preferable de mettre a jour chaque stack a part
				}
			}
			if (cost_b == 0 && cost_a > 0)
			{
				while (cost_a != 0)
				{
					ra(a);
					update_stacks(a, b);
					cost_a = temp->cible->cost;
				}
			}
			if (cost_a == 0 && cost_b == 0)
			{
				tempb = temp->next;
				pa(a, b);
				// show(a,b,0);
				update_stacks(a, b);
			}
		}
		else if (cost_a <= 0 && cost_b <= 0)
		{
			while (cost_a != 0 && cost_b != 0)
			{
				rrr(a, b);
				update_stacks(a, b);
				cost_b = temp->cost;
				cost_a = temp->cible->cost;
			}
			if (cost_a == 0 && cost_b < 0)
			{
				while (cost_b != 0)
				{
					rrb(b);
					update_stacks(a, b);
					cost_b = temp->cost;
				}
			}
			if (cost_b == 0 && cost_a < 0)
			{
				while (cost_a != 0)
				{
					rra(a);
					update_stacks(a, b);
					cost_a = temp->cible->cost;
				}
			}
			if (cost_a == 0 && cost_b == 0)
			{
				tempb = temp->next;
				pa(a, b);
				// show(a,b,0);
				update_stacks(a, b);
			}
		}
		else if (cost_a <= 0 && cost_b >= 0)
		{
			while (cost_a != 0)
			{
				rra(a);
				update_stacks(a, b);
				cost_a = temp->cible->cost;
			}
			if (cost_b > 0)
			{
				while (cost_b != 0)
				{
					rb(b);
					update_stacks(a, b);
					cost_b = temp->cost;
				}
				if (cost_b == 0)
				{
					tempb = temp->next;
					pa(a, b);
					// show(a,b,0);
					update_stacks(a, b);
				}
			}
		}
		else if (cost_b <= 0 && cost_a >= 0)
		{
			while (cost_a != 0)
			{
				ra(a);
				update_stacks(a, b);
				cost_a = temp->cible->cost;
			}
			if (cost_b < 0)
			{
				while (cost_b != 0)
				{
					rrb(b);
					update_stacks(a, b);
					cost_b = temp->cost;
				}
				if (cost_b == 0)
				{
					tempb = temp->next;
					pa(a, b);
					// show(a,b,0);
					update_stacks(a, b);
				}
			}
		}
	}
}
