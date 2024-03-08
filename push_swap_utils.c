/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:25:08 by asabir            #+#    #+#             */
/*   Updated: 2024/03/08 17:56:39 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_t_node(int value)
{
	t_node	*pm;

	pm = (t_node *)malloc(sizeof(t_node));
	if (pm != NULL)
	{
		pm->value = value;
		pm->position = 0;
		pm->order = -1;
		pm->next = NULL;
	}
	return (pm);
}

void	add_node_to_stack(t_stack *pile, t_node *pm)
{
	t_node	*temp;

	temp = pile->head;
	if (temp == NULL)
		pile->head = pm;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = pm;
	}
}

t_stack	*create_t_stack(char **str)
{
	int		i;
	int		nbr;
	t_node	*pm;
	t_stack	*pile;

	i = 0;
	pile = (t_stack *)malloc(sizeof(t_stack));
	if (!pile)
		free_and_exit(pile, 0);
	pile->head = NULL;
	while (str[i] != NULL)
	{
		nbr = ft_atoi(str[i]);
		if (!check_if_number(str[i]) || !check_if_integer(nbr)
			|| !check_duplicate(pile, nbr))
			free_and_exit(pile, 1);
		pm = create_t_node(nbr);
		add_node_to_stack(pile, pm);
		i++;
	}
	set_order(pile);
	return (pile);
}

void	update_position(t_node **a)
{
	int		i;
	t_node	*temp;

	i = 0;
	if (!*a)
		return ;
	temp = *a;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

t_stack	*initialize_b_t_stack(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->head = NULL;
	return (b);
}
