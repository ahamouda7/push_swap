#include "push_swap.h"

int	isdup(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;

	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
