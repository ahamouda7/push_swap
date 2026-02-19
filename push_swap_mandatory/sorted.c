#include "push_swap.h"

int	sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > (stack_a->next)->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}