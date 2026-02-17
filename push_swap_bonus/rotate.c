#include "push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*first;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
