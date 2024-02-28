#include "push_swap.h"

int check_duplicate(stack *pile, int nbr)
{
	node *temp;

	if (pile == NULL)
		return (0);
	temp = pile->head;
	while (temp != NULL)
	{
		if (temp->value == nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}
int check_if_interger(int c)
{
	if (c >= INT_MIN && c <= INT_MAX)
		return (1);
	else
		return (0);
}
// int check_if_number(int c)
// {
// }
void free_and_exit(stack *a, stack *b)
{
	while (a->head)
	{
		a->head = a->head->next;
	}
	free(a);
	free(b);
	write(1, "", )
		exit(1);
}
