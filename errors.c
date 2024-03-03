/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:15:33 by asabir            #+#    #+#             */
/*   Updated: 2024/03/03 20:20:34 by asabir           ###   ########.fr       */
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

void	free_matrice(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// tal vez tengo q iniciar la cabeza de mi t_stack cn null
void	free_and_exit(t_stack *a, int display)
{
	t_node	*tmp;

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
	if (display == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(0);
}
