#include "push_swap.h"

void	set_index(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;

	i = stack_a;
	while(i)
	{
		i->index = 0;
		j = stack_a;
		while(j)
		{
			if (j->value < i->value)
				(i->index)++;
			j = j->next;
		}
		i = i->next;
	}
}
