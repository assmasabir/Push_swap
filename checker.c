/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:08:48 by asabir            #+#    #+#             */
/*   Updated: 2024/03/04 14:42:50 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_instructions_on_stack(char *inst, t_stack *a, t_stack *b)
{
	if (ft_strcmp(inst, "pb\n") == 0)
		pb(b, a);
	else if (ft_strcmp(inst, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(inst, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(inst, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(inst, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(inst, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(inst, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(inst, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(inst, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(inst, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	read_and_move(t_stack *a, t_stack *b)
{
	char	*inst;
	int		i;

	inst = "just initializing";
	while (inst)
	{
		inst = get_next_line(0);
		if (inst)
		{
			i = apply_instructions_on_stack(inst, a, b);
			if (i == 0)
			{
				free(inst);
				return (0);
			}
		}
		free(inst);
	}
	return (1);
}

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

int	main(int argc, char **argv)
{
	char	**str;
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		a = create_t_stack(str, argc - 1);
	}
	else
		a = create_t_stack(argv + 1, argc - 1);
	b = initialize_b_t_stack();
	i = read_and_move(a, b);
	if (i == 0)
		free_and_exit(a, b, 1);
	if (!check_if_stack_sorted(a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_and_exit(a, b, 0);
}
