/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:15:33 by asabir            #+#    #+#             */
/*   Updated: 2024/03/04 14:37:39 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *pile, int nbr)
{
	t_node	*temp;

	if (pile == NULL)
		return (0);
	temp = pile->head;
	while (temp != NULL)
	{
		if (temp->value == nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_if_integer(long c)
{
	if (c >= INT_MIN && c <= INT_MAX)
		return (1);
	else
		return (0);
}

int	check_if_number(char *str)
{
	int	i;
	int	var;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	var = i;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	if (i != 0 && var == i)
		return (0);
	return (1);
}

// tal vez tengo q iniciar la cabeza de mi t_stack cn null
void	free_and_exit(t_stack *a, t_stack *b, int display)
{
	t_node	*tmp;

	if (b && b->head)
	{
		while (b->head)
		{
			tmp = a->head;
			b->head = b->head->next;
			free(tmp);
		}
		free(b);
	}
	if (a->head)
	{
		while (a->head)
		{
			tmp = a->head;
			a->head = a->head->next;
			free(tmp);
		}
		free(a);
	}
	exit(display);
}

void	exit(int display)
{
	if (display == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
